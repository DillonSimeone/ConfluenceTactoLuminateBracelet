/*
Last modified on: 1/23/2024

Confluence - Universial Music Design
  Gestolumina Prototype 1

Sends MIDI notes over bluetooth (BLE-MIDI). Sensors on the ring and the accelermeter controls the notes, pitch, speed, etc.

Programmer: Dillon Simeone
*/

#include "pin_config.h"
#include <Wire.h> //pin 43: SDA pin 44: SCL. Is the default pins of LilyGo. 

//Screen
#include <SPI.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h


//Bluetooth
#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
BLEMIDI_CREATE_INSTANCE("Gestolumina Prototype 1", MIDI)

//ET's index finger
#define finger1Led 16
#define finger1FSR 2
#define finger1HallwaySensor 3 //It's kinda of tricky to trigger those hallway sensors. They require magnets touching them precisely right or they won't trigger. Maybe stronger magnets are required?
int finger1HallwaySensorState;
int finger1HallwaySensorPreviousState = LOW;
unsigned long finger1HallwaySensorlastDebounceTime = 0;
unsigned long debounceDelay = 50;

//Mic pins
#include <AudioInI2S.h>
#include <AudioAnalysis.h>
#define BCK_PIN 21
#define WS_PIN 18
#define DATA_PIN 17 
#define CHANNEL_SELECT_PIN 40 //L/R channel, not in use.
AudioInI2S mic(BCK_PIN, WS_PIN, DATA_PIN, CHANNEL_SELECT_PIN); // defaults to RIGHT channel.
#define SAMPLE_SIZE 1024 // Buffer size of read samples
#define SAMPLE_RATE 44100 // Audio Sample Rate
int32_t samples[SAMPLE_SIZE]; // I2S sample data is stored here
#define BAND_SIZE 8 // powers of 2 up to 64, defaults to 8
AudioAnalysis audioInfo;


//MPU6050 sensor
#define IMU_ADDRESS 0x68    //Change to the address of the IMU
#include "I2Cdev.h"
#include "FastIMU.h" //Pretty fire library that made a lot of the set-up painless with the MPU.
MPU6050 IMU;
calData calib = { 0 };  //Calibration data
AccelData accelData;    //Sensor data
GyroData gyroData;

//SparkFun Qwiic Haptic Driver DA7280 Dillon's comment: This is WEAK as heck. I barely can notice it running even on max settings. Lame.
#include "Haptic_Driver.h"
Haptic_Driver hapDrive;
#define l298nMotor1 1

int counter = 0;

//Turns out when batteries are plugged into the LilyGo's battery charger port, the screen goes blank. Below is the fix.
#define PIN_POWER_ON 15 // LCD and battery Power Enable
#define PIN_LCD_BL 38 // BackLight enable pin (see Dimming.txt)

void setup() {
  Wire.begin(43, 44);  //SDA, SCL

  //Battery screen fix continued. 
  pinMode(PIN_POWER_ON, OUTPUT); //triggers the LCD backlight
  pinMode(PIN_LCD_BL, OUTPUT); // BackLight enable pin

  digitalWrite(PIN_POWER_ON, HIGH);
  digitalWrite(PIN_LCD_BL, HIGH);

  if( !hapDrive.begin())
    Serial.println("Could not communicate with Haptic Driver.");
  else
    Serial.println("Qwiic Haptic Driver DA7280 found!");

  if( !hapDrive.defaultMotor() ) 
    Serial.println("Could not set default settings.");
  hapDrive.enableFreqTrack(false);
  hapDrive.setOperationMode(DRO_MODE);

  pinMode(l298nMotor1, OUTPUT);

  pinMode(finger1Led, OUTPUT);
  pinMode(finger1HallwaySensor, INPUT_PULLDOWN);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2);
  tft.println("Calibrating sensors, keep on level surface...");

  int err = IMU.init(calib, IMU_ADDRESS);
  if (err != 0) 
    Serial.print("Error initializing IMU: "); 
  IMU.calibrateAccelGyro(&calib);
  tft.fillScreen(TFT_BLACK);
  tft.print("Sensors calibrated!");
  IMU.init(calib, IMU_ADDRESS);
  tft.fillScreen(TFT_BLACK);

  mic.begin(SAMPLE_SIZE, SAMPLE_RATE); // Starts the I2S DMA port.
  // audio analysis setup
  audioInfo.setNoiseFloor(10);       // sets the noise floor
  audioInfo.normalize(true, 0, 255); // normalize all values to range provided.
  // audioInfo.autoLevel(AudioAnalysis::ACCELERATE_FALLOFF, 1); // uncomment this line to set auto level falloff rate
  audioInfo.bandPeakFalloff(AudioAnalysis::EXPONENTIAL_FALLOFF, 0.05); // set the band peak fall off rate
  audioInfo.vuPeakFalloff(AudioAnalysis::EXPONENTIAL_FALLOFF, 0.05);    // set the volume unit peak fall off rate

  MIDI.begin();
}

void mpu6050Colors(float data){
  if(data > 0.5)
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  if(data > 1)
    tft.setTextColor(TFT_PURPLE, TFT_BLACK);
  if(data > 1.5)
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  if(data > 2)
    tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.printf("%06.2f",abs(data));
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
}

void loop() {
  IMU.update();
  IMU.getAccel(&accelData);
  IMU.getGyro(&gyroData);

  //debounce magic for hallway sensor
  int finger1HallwaySensorReading = digitalRead(finger1HallwaySensor);

  if(finger1HallwaySensorReading != finger1HallwaySensorPreviousState)
    finger1HallwaySensorlastDebounceTime = millis();
  
  if((millis() - finger1HallwaySensorlastDebounceTime) > debounceDelay)
    if(finger1HallwaySensorReading != finger1HallwaySensorState)
      finger1HallwaySensorState = finger1HallwaySensorReading;

  finger1HallwaySensorPreviousState = finger1HallwaySensorReading;

  /* Get new sensor events with the readings */
  mic.read(samples); // Stores the current I2S port buffer into samples.
  audioInfo.computeFFT(samples, SAMPLE_SIZE, SAMPLE_RATE);
  audioInfo.computeFrequencies(BAND_SIZE);
  float *bands = audioInfo.getBands();
  float *peaks = audioInfo.getPeaks();
  float vuMeter = audioInfo.getVolumeUnit();
  float vuMeterPeak = audioInfo.getVolumeUnitPeak();

  //Setting up screen for magic
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setCursor(0,0,2);
  tft.println("Haptic Bracelet Project Sensor Readouts");
  tft.setTextFont(1);
  tft.print("Sanity test counter:");
  tft.println(counter);
  counter++;
  if(counter > 9)
    counter = 0;
  
  tft.setTextColor(TFT_ORANGE, TFT_BLACK);
  tft.println("Acceleration and rotation data is flipped!");
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.print("Acceleration X: "); //Oddly, it seems that acceleration on this mystery MPU is actually the rotation?
  mpu6050Colors(accelData.accelX);

  tft.print(", Y: ");
  mpu6050Colors(accelData.accelY);

  tft.print(", Z: ");
  mpu6050Colors(accelData.accelZ + 1);
  tft.println(" m/s^2");
  tft.print("3D vector sum of x, y and z acceleration: ");
  double totalAcceleration = sqrt(
    accelData.accelX * accelData.accelX +
    accelData.accelY * accelData.accelY +
    accelData.accelZ * accelData.accelZ);
  tft.println(totalAcceleration);
  tft.println("");

  tft.print("Rotation X: ");
  mpu6050Colors(gyroData.gyroX);
  tft.print(", Y: ");
  mpu6050Colors(gyroData.gyroY);
  tft.print(", Z: ");
  mpu6050Colors(gyroData.gyroZ);
  tft.println(" rad/s");
  tft.print("3D vector sum of x, y and z rotation: ");
  double totalAcceleration2 = sqrt(
    gyroData.gyroX * gyroData.gyroX +
    gyroData.gyroY * gyroData.gyroY +
    gyroData.gyroZ * gyroData.gyroZ);
  tft.println(totalAcceleration2);
  //Midi velocrity
  tft.println("");

  int midiVelocity = map(totalAcceleration2, 0, 500, 0, 127);
  tft.print("Midi Velocity: ");
  tft.println(midiVelocity);
  tft.println("");

  /*
  tft.print("Temperature: ");
  tft.print(IMU.getTemp());
  tft.println(" degC");
  */ 

  tft.println("Frequency band perks: ");

  for (int i = 0; i < BAND_SIZE; i++){
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.printf("%d:", i);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.printf("%06.2f | ", peaks[i]);
    if(i%3 == 0 && i > 0) // Is an even loop and not zero
      tft.println(""); // Line break.
    if(peaks[1] > 50)
      digitalWrite(finger1Led, HIGH);
    else
      digitalWrite(finger1Led, LOW);
  }
  tft.println("");

 

  // also send the vu meter data
  tft.printf("Volume Unit Value:%06.2f\nVolume Unit Peak :%06.2f\n", vuMeter, vuMeterPeak);
  tft.println("");

  tft.print("Finger1Hallway readings: ");
  if(finger1HallwaySensorReading != 0)
    tft.setTextColor(TFT_YELLOW, TFT_BLACK); //I should turn this into a function... Hmm. Accepts string, colors, colors. Switch to color 1 for output, then go back to color 2. 
  tft.println(finger1HallwaySensorReading);
  tft.setTextColor(TFT_GREEN,TFT_BLACK);
  

  tft.print("Finger1FSR readings: ");
  double finger1FSRReading = analogRead(finger1FSR);

  if(finger1FSRReading < 25){
    tft.setTextColor(TFT_GREEN,TFT_BLACK);
    hapDrive.setVibrate(0);
    digitalWrite(l298nMotor1, LOW);
    MIDI.sendNoteOn(60, midiVelocity, 1); //Note, speed, channel
  }
  if(finger1FSRReading > 50){
    hapDrive.setVibrate(127); //So weak... I barely can feel the vibrations. This is the max settings.
    digitalWrite(l298nMotor1, HIGH);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    MIDI.sendNoteOn(61, midiVelocity, 1); 
  }
  if(finger1FSRReading > 75){
    tft.setTextColor(TFT_RED, TFT_BLACK);
    MIDI.sendNoteOn(62, midiVelocity, 1);
  }
  if(finger1FSRReading > 100){
    tft.setTextColor(TFT_PURPLE, TFT_BLACK);
    MIDI.sendNoteOn(63, midiVelocity, 1); 
  }  

  tft.printf("%03d", (int)finger1FSRReading);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  MIDI.sendNoteOn(midiVelocity, map(finger1FSRReading, 0, 200, 0, 127), 2); // 200 seems to be the hardest I can press it without the sensor going wonky.
  MIDI.sendNoteOn(midiVelocity, map(vuMeterPeak, 0, 100, 0, 127), 3); //The mic broke before this was coded in, so I'm just recalling numbers from memory. I think the meterPeak ranged from 0 to 100, from testing via shouting at the mic.
  MIDI.sendNoteOn(map(vuMeterPeak, 0, 100, 0, 127), midiVelocity, 4);

  delay(50); //No special reasons for choosing 50ms. It just works. Going faster seems to work fine. I've heard that you need to have at least 2ms delay or you'll get the same readings from the MPU-6050 sensor.
}