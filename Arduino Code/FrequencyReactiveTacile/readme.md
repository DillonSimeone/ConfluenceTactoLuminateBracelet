# Device Description
This sends out midi notes via bluetooth (BLE-MIDI). The sensors on the ring and MPU-6050 affects what notes are sent, velocity, etc.

# Libraries
MPU sensor data + calibration
https://github.com/LiquidCGS/FastIMU

Audio processing
https://github.com/sheaivey/ESP32-AudioInI2S

Arduino BLE-MIDI
https://github.com/lathoub/Arduino-BLE-MIDI 

Sparkfun Haptic Driver
https://github.com/sparkfun/SparkFun_Qwiic_Haptic_Driver_DA7280_Arduino_Library

# Hardwares
TODO - write about the hardwares



# Midi notes programmed
	Channel 1:
		FSR controls midi notes between 60-64 to be sent, depending on how hard you press (25g intervals)
		Accelerometer controls the midi velocity
	Channel 2:
		Accelerometer controls what midi notes are sent
		FSR controls the midi velocity
	Channel 3:
		Accelerometer controls what notes are sent
		Audio level controls midi velocity
	Channel 4:
		Audio level controls what notes are sent.
		Accelerometer controls midi velocityFSR output: 0-200, mapped to 0-127 for midiAccelerometer output: 0 - lightspeed, capped to 0-500 and mapped to 0-127 for midi
