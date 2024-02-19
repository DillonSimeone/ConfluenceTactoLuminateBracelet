# Device Description
This sends out midi notes via bluetooth (BLE-MIDI). The sensors on the ring and MPU-6050 affects what notes are sent, velocity, etc.

# Libraries
<h4>MPU sensor data + calibration</h4>
<blockquote>
	https://github.com/LiquidCGS/FastIMU
	<p>Made it really easy to just plug those MPU sensors in and be done with it!</p>
</blockquote>

<h4>Audio processing</h4>
<blockquote>
	https://github.com/sheaivey/ESP32-AudioInI2S
	<p>Does magic on the audio to get frequency data, volume level, etc.</p>
</blockquote>

<h4>Arduino BLE-MIDI</h4>
<blockquote>
	https://github.com/lathoub/Arduino-BLE-MIDI 
	<p>Bluetooth to MIDI</p>
</blockquote>

<h4>Sparkfun Haptic Driver</h4>
<blockquote>
	https://github.com/sparkfun/SparkFun_Qwiic_Haptic_Driver_DA7280_Arduino_Library
	<p>Haptics</p>
</blockquote>



# Hardwares
<div>
	<h4>Mircocontroller</h4>
	<blockquote>
		<a href="https://www.amazon.com/LILYGO-T-Display-S3-ESP32-S3-Development-Soldered/dp/B0BF542H39/">LilyGo T-Display-S3</a>
		<p>Tiny, bluetooth, wifi, battery charge controller, LCD display and pins. What more can a guy ask for?</p>
	</blockquote>
	
</div>

<div>
	<h4>Battery</h4>
	<blockquote>
		<a href="https://www.amazon.com/MakerFocus-Rechargable-Protection-Insulated-Development/dp/B08T6QS58J/?th=1">3.7V Lithium Rechargeable Battery</a>
		<p>Cheap batteries.</p>
	</blockquote>
	
</div>

<div>
	<h4>Haptics</h4>
	<blockquote>
		<a href="https://www.amazon.com/SparkFun-Qwiic-Haptic-Driver-Built/dp/B096YHK485">SparkFun Haptic Driver</a>
		<b> NOT IN USE, TOO WEAK TO NOTICE</b>
		<p>Sparkfun marketed those as accurate audio to haptic hardwares... They did not mention that they're so weak that it takes effort to notice them.</p>
		<a href="https://www.amazon.com/SparkFun-development-soldering-Breadboardable-Chain-able/dp/B07RB2LRH5">Cable hook up kit</a>
		<b> NOT IN USE, NO OTHER I2C QWICC SENSORS IN USE. </b>
		<p>Ordered specifically for the Sparkfun Haptics, just to see how those cables are like.</p>
		<a href="https://www.amazon.com/dp/B0C5JCF5RS">L298N</a>
		<p>Good old time-tested H-bridges. They just work, and will happily melt your haptics if you run way too much power through them. They're awesome... The best!</p>
		<a href="https://www.amazon.com/tatoko-Vibration-Button-Type-Vibrating-Appliances/dp/B07Q1ZV4MJ/">Mini Vibration Motors </a>
		<p>Those actually works with a range of 3v to 5v without much issues. Nice and cheap.</p>
	</blockquote>
	
</div>

<div>
	<h4>Microphones</h4>
	<blockquote>
		<a href="https://www.amazon.com/dp/B092HWW4RS">INMP441</a>
		<p>Time-tested microphones, countless people have used those with great success.</p>
	</blockquote>
</div>

<div>
	<h4>Hallway Sensors</h4>
	<blockquote>
		<a href="https://www.amazon.com/SparkFun-Hall-Effect-Sensor-AH1815-Non-Latching/dp/B07DM7WBCG">AH1815</a>
		<p>Time-tested hallway sensors. There's many uses for them.</p>
	</blockquote>
</div>

<div>
	<h4>Film Pressure Sensor</h4>
	<blockquote>
		<a href="https://www.amazon.com/dp/B07T1CHY58">DF9-16 High Precise Force Sensitive Resistor</a>
		<p>Tiny and cheap, they work for fingertips.</p>
	</blockquote>
	
</div>


<div>
	<h4></h4>
	<a href=""></a>
	<p></p>
</div>


# Midi notes programmed
	Channel 1:
		Accelerometer - Sends Midi Note 53 when moved quickly enough in any directions, velocity affected by top speed.
	Channel 2:
		Index finger - Sends Midi Note 43, velocity affected by how hard the FSR is pressed.
	Channel 3:
		Middle finger - Sends Midi Note 39, velocity affected by how hard the FSR is pressed. 

