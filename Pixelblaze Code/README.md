# Intro
<h3>Pixelblaze</h3>
<p>An awesome led controller ESP32 commonly used by burning man partygoers, due to its live coding ability and how easy it is to connect it to nearly any LED lightings along with analog input/outputs.</p>
<h4 align="center"><a href="https://electromage.com/pixelblaze">Pixelblaze Website</a></h4>

<p>
  Gestolumina's first prototype used a pixelblaze V3 along with a <a href="https://electromage.com/docs/sensor-expansion-board">sensor extension</a>, making it very easy to get up and running right away. Barely any soldering needed, slap the hat on and you're ready to get to casting led magic!
</p>

<p>
  One thing that was made really easy with this system was beats detection. An audio engineer, Jeff Vyduna, was able to come up with a script that detects beats per minutes by looking for drops and rises across certain frequencies within a certain time frame. It works really well! We was able to extract his beats detection algorithm and modifiy it into a beats per minute detector pretty easily, making it possible to modify current animations based on the current beats per minute. 
</p>
