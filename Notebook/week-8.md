# Week 8 (4/3/18 - 4/9/18)

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
My design and implementation of internal map rely on several formulae I derived from trigonometry, which might not be sufficiently explained in my code comments, so I'll briefly explain my reasoning here in case anyone is curious.

To begin with, we know the distances traveled by the left wheel and right wheel, and the width of the vehicle -- we'll use these three pieces of information to derive the formulae. For convenience I'll use x, y and L to represent them. x and y will not be measured (since the encoders don't work very well for our purpose), but will be determined by the commands we send to the two servos. We are assuming the servos travel the distance we instruct them to, which might not be entirely true but we don't need our internal map to be entirely accurate either.
    distance traveled by the left wheel -> x
    distance traveled by the right wheel -> y
    width of the vehicle -> L
Note that these three variables must have the same unit! I measured the distance traveled by the vehicle with Drive(50, 50, 10) in centimeters (15cm for now, but might change in the future as we switch to bigger wheels or as battery power drains). Thus we will use the distance traveled by Drive(1, 1, 1) as the basic unit for all our length measures (0.03cm for now). The width of the vehicle is measured to be 12cm, and we'll convert that to our Drive(1, 1, 1) unit (400). By using  Drive(1, 1, 1) as the basic unit, we can simply modify the Drive(ls, rs, d) function to increment a left counter and a right counter by ls*d or rs*d to get x and y. I defined a timer that will add1 for every loop run; the counters and the timer will be checked and reset to zero every time the timer hits 10. Such frequency of checking is required to ensure relative accuracy.

Here are the steps I used to derive the three formulae:
![pg1](/Photos_and_Videos/Week8/pg1.png)
![pg2](/Photos_and_Videos/Week8/pg2.png)

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
