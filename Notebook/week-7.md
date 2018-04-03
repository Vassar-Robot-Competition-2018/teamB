# Week 7 (3/27/18 - 4/2/18)

## Progress Made:

### Entry by Steven Park:

Given the amount of progress we made over Spring Break, I believe we started the second half of this course with the proper footing. 
When the three of us met during the lab, we both agreed on two primary goals: the 3D model and the shaft encoders.

So far, our current robot has served us well and completed the first six milestones despite the fact that the servo motors were held down by take and the large wheels were attached to the servos with hot glue.
However, it's clear that this prototype is slowly reaching the end of its lifespan. The tape is wearing off, causing the servos and the wheels to bend outwards when the robot moves, which not only displaces the calibration of the RGB sensor but makes me fear that the servos may suddenly pop off the robot.
In addition, since the other groups have moved onto 3D printing, I figured it's time for us to do the same.

Thus, both Wenxuan and I have been working on the 3D model so that we could print out the parts and replace the prototype parts.
Wenxuan and I actually decided to work on two different 3D models for the sake of efficiency. 
Wenxuan worked on a full-scale 3D model, which will produce parts that will replace the prototype robot body entirely. She has spent most of the week measuring the various dimensions of the robot to create a complete upgraded version in OpenSCAD.
Her goal, she told me, is to replace every Lego, Bionicle, and foam part of the robot body.
Meanwhile, I'm working on the base 3D model in Rhino3D. Rather than create a complete model of the robot, my objective is to create a base that will hold the servos in place and replace the foam boards of the body.
While Wenxuan's model is the model that we'll ultimately end up using, I wanted to create this temporarily model to both test the 3D printer and fins a temporary solution to the servo problem. Ultimately, these 3D parts will only replace the foam boards.
However, since this model is smaller, I can finish it quicker and even if Wenxuan's model somehow not end up working, we have alleviated the most concerning problem, which is the fact that the servos are coming loose.

![Base 3D Model](/Photos_and_Videos/Week7/base_3D_model.PNG)

The other goal is to work on the shaft encoders, which has become Shihan's responsibility. Several weeks ago, Shihan bought shaft encoder sensors to track the movement of the wheels and record the path that the robot is traveling.
As a result, the robot will create an internal map of its movements and use that to return to its home base rather than randomly searching for it. 
These shaft encoders are important because in the second half of the course, a lot of the milestones have to do with pushing a block back to our region. Since the camera is programmed to only see the blocks and not the tape, we have to rely on the shaft encoders to give the robot its "sight".
However, this week, Shihan discovered that he needs to buy another set of shaft encoders in order to measure the robot's movements going backwards. Our plan is to talk to Prof. de leeuw about our design and ask us to buy more shaft encoders for us.
If the shaft encoders don't work, we may have to resort to using the camera somehow because that's the only sensor that can detect color at a distance. Unfortunately, our Arduino board only allows one Pixy camera it seems, so we may have to modify our current camera to see both the blocks and the tape.
That, of course, reopens the problem of how the camera can detect the difference between a block and tape. We thought that perhaps we can use the size of the objects detected to tell the difference (since the camera often sees the tape as one large object), but that solution is complicated by the fact that the tape may appear smaller if objects are placed in front of it in the camera's line of vision.
Another potential solution is to use IR sensors or an ultrasonic sensor to detect the presence of an obstacle in front of the robot. This way, the camera may see both the tape and the blocks, but whether the IR or sonar senses the object will determine whether what is in front of it is a block or tape.
Unfortuntately, a potential problem with that is how the robot will connect the objects detected by the camera with the object detected bu the IR/sonar. 
For instance, if a blue block is right in front of the robot but the camera sees red tape in the distance, the red tape may be detected as the bigger, and thus the closer, object by the camera. At the same time, the IR/sonar will detect the presence of the block and return true.
As a result, the camera may think what is in front of the robot right now is a red block instead of a blue block. We'll just have to wait and see what Prof. de Leeuw thinks about the shaft encoder sensors.

A special shout-out goes to Shihan for single-handedly finishing Milestone 7. According to him, it was easy to write the code because it was a simple variant of one of our previous milestones.
For once, we're actually in the lead among the other groups.

While most of my time was spent on the 3D model, I also performed several miscellaneous tasks as well, such as constructing a wheeled appendage on the back of the robot to prevent the robot from shaking too much as it moves.
I also shortened the length of thr front of the robot to help with the movement problem. Finally, in order to help Shihan test his shaft encoders, I created an appendage out of Lego that would place the shaft encoder directly next to the magnet on the outside of the wheel.
One thing to note about the shaft encoders is that ideally it should be placed on the inside of the wheel rather than on the outside. However, because there is very little space between the servo and the wheel, we're forced to place it outside. 
As a result, we may need to 3D print a tire shell for the wheels to not only attach the shafter encoders on the inside of the shell and keep it still but also to portect the shaft encoders from interference in case force is applied to the sides of the robot.


### Entry by Shihan:


### Entry by Wenxuan:
I re-soldered the RGB sensor because Phil said that the soldering filler material needs to cover the gold ring on the RGB sensor, when I thought that the lesser the material, the better (as long as the soldering shape looks right).

Then I started to use Openscad to construct 3D model to be printed. This task was important and needed very meticulous measurement of each component. Although I found some datasheet about each component online, I still measured them myself. Initially I thought that if I need to make a hole, the hole's diameter needed to be slightly larger than the measurement, or the stuff going through the hole would be stuck. Therefore, I often made the hole a little bit bigger than the measurement. The modelling was very complicated in terms of the putting parameters or variables in. I did the sketch for each component but I didn't draw down the model but just constructed the model on Openscad. Because there were way too many measurements and variables, I didn't create any global variables, even if I realized that then it meant that only I could read my own code based on the sketch I had. Still it was a serious problem because it meant that it would be hard to change the design later. However, I used addition and subtraction to indicate each step I took, instead of using one number. Moreover, Steven gave me some examples of components when 3D printer would be hard to print. Therefore, I changed my design a little bit to be better printed. 

![Sketch_1](/Photos_and_Videos/Week7/Sketch_1.JPG)

![3D_model](/Photos_and_Videos/Week7/Openscad_model.png)

Then I consulted with Nick, and he still suggested me creating a Variable List. Also, he said that it would be ideal to be as accurate as possible and there would a way to deal with holes that are too small, but we could do nothing about big holes. Moreover, he also gave some suggestions on my design, such as whether print some component to be one part or several parts. As a result, I'm designing a model again, creating a big variable list. I also measured the components again and did some sketch on the overall design

![Sketch_1_modified](/Photos_and_Videos/Week7/Sketch_1_modified.JPG)

![Sketch_2](/Photos_and_Videos/Week7/Sketch_2.JPG)

## Division of Labor
**Steven Park**
- Constructed the backwheels to restrict the robot from shaking
- Shortened the length of the front of the robot
- Found 8 screws and nuts to affix the servos
- Worked on and finished the base 3D model
- Created an appendage to temporarily hold the shaft encoder next to the wheel

**Wenxuan Guo**
- Re-soldered the connection to the RGB sensor
- Worked on the full-scale 3D model

**Shihan Zhao**
- Implemented the y-axis restriction on the camera (camera does not process anything below a certain y-value)
- Worked on and finished Milestone 7
- Worked on the shaft encoder sensors
