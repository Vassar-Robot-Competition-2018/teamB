# Week 7 (4/3/18 - 4/9/18)

## Progress Made:

### Entry by Steven Park:
The focus for this week was 3D modeling. At its current state, the robot body desperately needed an upgrade: The servos were coming loose and falling off and the foam boards needed to be replaced.
Thus, my main goal was to design and 3D print a temporary main body where the servos are firmly attached. Despite the fact that Wenxuan was also working on her 3D model, this was urgent because after multiple rounds of testing the shaft encoders, Shihan needed the servos to be attached firmly to the base in order to properly implement the sensors.
Since Wenxuan's model was taking a long time, I went ahead and quickly designed and 3D printed the base just so that our group work didn't come to a standstill.
While I only wanted to print the bottom base for the robot (the part where the servos would be attached), I ended up printing this model twice by accident. However, to my surprise, I found that stacking the two 3D printed models (one upside down and one rightside-up) created the perfect sturdy base for the robot.
Afterwards, I spent a lot of time configuring the body and appendage of the robot yet again due to the changes I had to implement with the printed models (the 3D printer only allowed a certain size, so I had to adjust the placement of certain parts to accomodate).
The end result was a simpler, cleaner version of the robot that not only had the servos firmly attached but also didn't need the large foam wheels that was superglued on the original servo wheels).
My hopes is that this version of the robot should allow Shihan to continue with his sensor testing so that he can implement the robot's internal map so that the robot keeps track of its movements and not move around aimlessly in the arena.


### Entry by Shihan:


### Entry by Wenxuan:
I reprogrammed my model in openscad because I found that creating a variable list would be much more convenient for further changes. I also redid the calculation to center everything, which also helps with later adjustment. I also tried to reduce the weight of the model.
![CodeChange](/Photos_and_Videos/Week8/Code.png)

For the upper base, a seperate camera board would be attached by sliding in through the hole in the base. The camera board have holes in it so that the pixy camera can be screwed on. 
![UpperBase](/Photos_and_Videos/Week8/UpperBase.png)

Since the height of the camera board is undecided, depending on where we want to put our camera, the model is not set, but it would look like this:
![Camera](/Photos_and_Videos/Week8/CameraBoard.png)

For the lower base, a seperate RGB board and two arms would be attached to the front wall. The front wall also has another hole for the wires of the battery to be placed. The four cubes are used to stablize the servos. A back wall is put in place to prevent the battery from falling out.
![LowerBase](/Photos_and_Videos/Week8/LowerBase.png)
![RGBBoard](/Photos_and_Videos/Week8/RGB board.png)

## Division of Labor
**Steven Park**
- Finished the 3D model of the base in Rhino3D
- Printed out the 3D model and configured the entire body of the robot to adhere to this new design

**Wenxuan Guo**
- Worked on the full-scale 3D model

**Shihan Zhao**
- Worked on the shaft encoder sensors
