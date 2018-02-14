# Week 2 (2/6/18 - 2/12/18)

## Progress Made:

### Entry by Steven Park:
After some more brainstorming, our group decided on the final design for the robot. It's only a preliminary and may be subject to change depending on our circumstances.

For our design, we decided on the following:
- a square body
- two very large wheels on opposite sides that cover the sides of the robot. The wheels are large to help with efficient travel and balance
- on the remaining two sides are a pair of long, static prongs, almost like deer antlers. This way, we don't have to worry about establishing motors on the robot's "arms". It's both simple and efficient. The reason why there are prongs on both sides is to cut the time on travel. The robot can push the necessary blocks into the right region and then instead of turning around, it can move backwards instead.
- a camera stationed on a 360-degree servo at the very top of the robot. The servo should allow the camera to turn 360-degrees, thus giving the robot more opportunities for greater mobility

For this week, out main goal was to connect the wheels/servos on the main body of the robot and start attaching all the various sensors. 
As it turns out, we have to incorporate a lot of sensors:
- 1 camera
- 1 360-degree servo (excluding the wheels)
- 2 line-detecting sensors
- 4 IR sensors
- switch
- 3 LED lights
- 2 RGB color sensors

The reason behind the large number of needed sensors is because we essentially want our robot to have *two fronts* instead of a front and a back.
We may need a large breadboard but hopefully, the one we have should be enough. 

Unfortunately, progress was rather slow this week as we came across a few problems with the code. Since our second milestone has to do with the robot recognizing the white borders of the area, the first sensor we tackled was the line-detecting sensor.
Although we had to sauter our line-detecting sensor in order to test it, we managed to obtain an old line-detecting sensor that was already sautered, albeit very poorly.
Both Wenxuan and I tried to figure out the code for this sensor, but for some reason, we had difficulty getting the sensor to send different signals when it detected various levels of brightness.
Regretfully, trying to understand and debug this sensor took up more time than we desired. Even worse is that we still haven't fully debugged it.

Another strange problem we came across was that sometimes, when we worked with the camera, there would be a runtime error whenever we tried to upload the Arduino code. This error would make the uploading take forever to load and ultimately crashed our computers.
It is unclear if this runtime error has to do with a problem with the code or perhaps the circuits being overworked (probably the code). For now, we got rid of the error and hopefully, this issue doesn't arise again.
Speaking of which, Shihan made great progress with the camera. He successfully got the camera to pick up the four different colors and he programmed the Arduino code so that the robot body moved towards the respective colors whenever the camera identified them.
This marks our first successful link between a robot's sensor and its actuator. Hopefully, we can get the line-detecting sensors to do the same.

Meanwhile, I also started modelling the robot in Rhino3D, which is a 3D modelling software. Using Rhino3D, I plan to not only have a clear, detailed blueprint of our robot's final design but also create the files needed to 3D print the needed parts.
Given how one group has already made significant progress by 3D printing their robot's body, I plan to catch up to them.

For next week, we have to ask Prof. de Leeuw for advie regarding the line-detecting sensor. We should also sauter our own line-detecting sensor by then, especially since the already frayed wires of the old line-detecting sensor broke. Sautering the first thing our group should do.
I also wish to find a more suitable way to attach the sensors and actuators to the robot's boody since there's only so much we can do with tape.

### Entry by Shihan:
I had completed the bulk of camera codes the previous week, but wasn't able to test them on the actual robot. The debugging took me a couple of hours when I tried to compile and test them this Saturday, (since I hadn't worked with Arduino or Pixy before, and had to look up documents for reference) turned out I declared several variables with the wrong data type, and did the scaling with Drive() wrong. After bugs cleared, our robot can now drive towards the closest color block of a specific color (I used sizes of color blocks as the indicator for their proximity, so this was under the assumption that all blocks had the same sice). I also scaled the turning to make it more smooth (i.e. the farther off the object from main course, the greater the turning). As Steven pointed out, we experienced some unexpected difficulties with uploading the codes -- the uploading would time-out and eventually fail on my own computer, but would succeed on Steven's computer. When I returned to my computer and tried to upload sometime later, it succeeded, which added to the confusion even more. This greatly delayed our process. The most probable explanation I've found to this was that the firmwire was outdated, but again -- the problem just fixed itself, without firmwire update.
During this week's lab, I made some further progress by adding a switch and a RGB LED (a LED that can display many colors by using different satuations of red, green, and blue), so now our robot can (ideally) be switched on or off by a button, and display different LED colors when driving towards blocks of different colors. The codes on switch were unexpectedly complicated because we wanted the robot to actually "sleep" and conserve power rather than just execute delay. The codes were able to compile so there should be no semantic error; hopefully I can test the codes on our robot later this week.

### Entry by Wenxuan:
I first coded the line sensor used the code provided online, but we found that using micros() function was not working so we switched to using counter. We started counting when the digitalRead reported HIGH and counted up continuously every 20 millisecond using delay(20). If the counter was higher than 15 (an arbitrary number that needed to be fine-tuned to set the threshold), we know the object had low reflectance, and vice versa (Light objects absorb less IR signals and high reflectance back to the phototransistor would cause the output to go lower).

However, we found that digital reading of the line-detecting sensor didn't work in general, using digitalRead(), and the sensor failed to report "LOW" when a white/light object appear . Therefore we switched the sensor to analog mode and the sensor reported the value of the output. Unfortunately, the difference of the analog values when the line sensor senses dark and light objects was very low (approximately 1010 for grey/black objects, and only changed to around 960 if the white tape was around 3~4cm near the sensor). Therefore we decided to map the values to make the differene higher. 

Another problem arose when we found that the line-detecting sensor did not differentiate bewteen blue and white tape (when it was near the blue tape, it also reported a low value). Therefore, I came up with the idea that we used the combination between the camera and the line-detecting sensor. Although the camera cannot tell whether the object is white, it can tell colored objects. So if line-detecting sensor reports a low value while the camera does not report it's a colored object, it means the robot has reached the border.

I also learned how to solder because the other two group members had some traumatic soldering experience. I need to remember to put on safety glasses and open the ventilation next time.

## Division of Labor
**Steven Park**
- Worked on the Arduino code for the line-detecting sensor
- Started working on the 3D model in Rhino3D in preparation for 3D printing parts

**Wenxuan Guo**
- Worked on the Arduino code for the line-detecting sensor
- Soldered the line-detecting sensor

**Shihan Zhao**
- Worked on the Pixy camera
- Wrote the Arduino code that connected the camera to the two servo motors
