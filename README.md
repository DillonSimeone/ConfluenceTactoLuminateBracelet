<h1 align="center"><a href="https://bejewelled-kelpie-6a1941.netlify.app/">Gestolumina</a></h1>
<h4 align="center">Gesture Interpreted Light, Sound and Haptics. Towards a Framework for Universal Music Design</h4>

<p align="center">
    <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/Gesloumina.jpg" style="width: 25%;">
</p>
<h1 align="center">Team Members</h1>
<table align="center">
    <thead>
        <th>Shawn Trail, PhD</th>
        <th>Nate Hergert</th>
        <th>Myles De Bastion</th>
    </thead>
    <tbody>
        <tr>   
            <td>CymaSpace</td>
            <td>CymaSpace</td>
            <td>CymaSpace</td>
        </tr>
        <tr>
            <td>www.cymaspace.org</td>
            <td>www.cymaspace.org</td>
            <td>www.cymaspace.org</td>
        </tr>
        <tr>
            <td>Portland, Oregon</td>
            <td>Portland, Oregon</td>
            <td>Portland, Oregon</td>
        </tr>
        <tr>
            <td>shawntrail@gmail.com</td>
            <td>nate@cymaspace.org</td>
            <td>myles@cymaspace.org</td>
        </tr>
    </tbody>
    
</table>
<table align="center">
    <thead>
        <th>Dillon Simeone</th>
        <th>Doga Cavdir, PhD</th>
    </thead>
    <tbody>
    <tr>
        <td>CymaSpace</td>
        <td>Medialogy</td>
    </tr>
    <tr>
        <td>www.cymaspace.org</td>
        <td>Aalborg University</td>
    </tr>
    <tr>
        <td>Portland, Oregon</td>
        <td>Copnenhagen, Denmark</td>
    </tr>
    <tr>
        <td>dillonsimeone@gmail.com</td>
        <td>Idoga.cadvir@gmail.com</td>
    </tr>
    </tbody>
</table>

# Intro
<p>
    Two different styles of bracelets are being built as custom musical instruments, one with pixelblaze and another with ESP32. The purpose of those bracelets are to control nearly haptics and LED systems via sensors detecting the wearer's gestures and movements. 
</p>
<h3><a href="https://github.com/DillonSimeone/Gestolumina/tree/main/Arduino%20Code/FrequencyReactiveTacile">ESP32 Bracelet (GestoLumina)</a></h3>
<p>A low cost but extremely powerful approach, very beginner-friendly due to being programmed in arduino. Require more elbow grease to get up and running similar to the pixelblaze. However, the bluetooth in nearly all ESP32s makes them very easy to program as bluetooth musical instruments!</p>

<h3><a href="https://github.com/DillonSimeone/Gestolumina/tree/main/Pixelblaze%20Code">Pixelblaze Bracelet</a></h3>
<p>The tool of choice for visualizing sounds with leds. This was the first quick rough prototype, since it was easy to order the sensor extension which comes with all sensors required for the project. Custom firmwork, somewhat accessiable due to its programming language being similar to javascript. No support for TFT displays, arduino libraries, etc. Not as straightfoward to set up as a musical instrument.</p>

# Misc
<h3>Prezi Show</h3>
<p>Confluence built this prezi show for workshops, to quickly give people a crash course into how CymaSpace handles sounds to lights and music theory.</p>
<h3 align="center"><a href="https://prezi.com/view/BKSwKoRpNLLlaCZ8I6HS/">View Prezi</a></h3>


# Videos
<h3>Misc</h3>
<ul>
    <li><a href="https://www.youtube.com/shorts/vZXHRAnROqk">Lasering parts out</a></li>
    <li><a href="https://www.youtube.com/shorts/q6HAHHKfm44">Random reverse engineering for bracelet straps</a></li>
</ul>
<h3>Pixelblaze</h3>
<ul>
    <li><a href="https://www.youtube.com/shorts/bQNIAE6hn9M">Making chassis</a></li>
    <li><a href="https://www.youtube.com/shorts/2__cOaNY4yM">Testing frequency reactive code</a></li>
    <li><a href="https://www.youtube.com/shorts/NpTJMvQrC3I">Testing beats per minute mode</a></li>
</ul>
<h3>GestoLumina</h3>
<ul>
    <li><a href="https://www.youtube.com/watch?v=SJd1xGemtCc">Testing Hallway Monitor</a></li>
    <li><a href="https://www.youtube.com/shorts/A8XjW7fpP0g">Testing ring led reacting to sounds</a></li>
    <li><a href="https://www.youtube.com/shorts/U4VskPwTADo">Testing MPU-6050 1</a></li>
    <li><a href="https://www.youtube.com/shorts/bvzDoGDOsoE ">Testing MPU-6050 2</a></li>
    <li><a href="https://www.youtube.com/shorts/jl-9ZZjW-vE ">Testing MPU-6050 3</a></li>
    <li><a href="https://www.youtube.com/shorts/bEWE7uyCt_Y ">Testing haptics</a></li>
    <li><a href="https://www.youtube.com/shorts/fWRVd8oUweI">Inching toward final form... Too bulky! The pins coming out of the ESP32 board are evil!</a></li>
</ul>

# Pictures
<h3>Pixelblaze</h3>
<table>
    <tr>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/assemblingLEDsPixelBlaze.jpg" style="width: 50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/assemblingLEDsPixelBlaze2.jpg" style="width: 50%;">
        </td>
        <td align="center">
           <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/assemblingLEDsPixelblaze3.jpg" style="width: 50%;">
        </td>
    </tr>
    <tr>
        <td align="center"> 
            <p>Cutting up and soldering together LED strips so they'll fit on the living hinge bracelet. </p>
        </td>
        <td align="center">
            <p>The pixelblaze bracelet lives!</p>
        </td>
        <td align="center">
            <p>Making a new bracelet and wiring the leds differently. Previously, they was wired in parallel.</p>
        </td>
    </tr>
</table>

<h3>ESP32 (GestoLumina)</h3>
<table>
    <tr>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/reilizingSensorsCanFitInMyRings.jpg" style="width: 50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/testingRingFits.jpg" style="width: 50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/assemblingSensorsOnRings2.jpg" style="width: 50%;">
        </td>
    </tr>
    <tr>
        <td align="center">
            <p>The moment when it was realized that most of the sensors would fit neatly into wooden rings made by a laser cutter.</p>
        </td>
        <td align="center">
            <p>Testing which ring size seems to fit on people's fingertips the best. 18mm~ turned out to be the ideal size for those ring designs.</p>
        </td>
        <td align="center">
            <p>Assembling sensors on the rings, it went by pretty nicely.</p>
        </td>
    </tr>
    <tr>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/testingFit.jpg" style="width: 50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/testingESP32Display.png" style="width: 50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/testingMics.jpg" style="width: 50%">
        </td>
    </tr>
    <tr>
        <td align="center">
            <p>It fits!</p>
        </td>
        <td align="center"> 
            <p>Displaying all sensor readouts on the screen for easier development and troubleshooting.</p>
        </td>
        <td align="center"> 
            We was careful to laser the box in a way where sensors and the like can be added or removed without desoldering wires, breaking the box, etc.
        </td>
    </tr>
    <tr>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/testingSparkFunHaptics.jpg" style="width:50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/showingHowFingerTipSensorsConnectsToESP32.jpg" style="width:50%;">
        </td>
        <td align="center">
            <img src="https://github.com/DillonSimeone/Gestolumina/blob/main/images/Gestolumina/idealGlove.jpg" style="width:50%">
        </td>
    </tr>
    <tr>
        <td align="center">
            <p>Testing the sparkfun haptic driver, it turned out to be really weak. Barely noticeable at max power. That's 3v haptics for you!</p>
        </td>
        <td align="center">
            <p>Added a L298N H-bridge to control the haptics with, much better!</p>
        </td>
        <td align="center">
            <p>This half glove is what the entire system will be sewn to eventually!</p>
        </td>
    </tr>
</table>


    
    
    
    
    
    
    
    
   


    


        
    
        
            

        
             

        
            
            
            

        
               
        
        
            

        
            
