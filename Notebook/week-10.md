# Week 10 (4/17/18 - 4/23/18)

## Progress Made:

### Entry by Steven Park:
For this week, most of our efforts were directed towards the final 3D print of the robot body. While the temporarily 3D model allows us to work with a fully functioning robot body, our initial plan was to create a 3D printed body that would replace all the Lego and Bionicle parts entirely.
Unfortunately, we kept encountering an endless flow of problems with the 3D printer. Every time we tried to print either the upper body or the lower body, the 3D printer would either mess us the print badly in the middle of the print or suddenly stop printing. 
As a result, Wenxuan and I probably attempted to print the robot body 5-6 times in that week, only to encounter failure with the printer every time.

At the same time, I was in the middle of planning how we could design the arms that would alow the robot to hold the block in front of the camera.
Although we brainstormed several ideas, we ultimately decided to use continuous servos to swing the arms left and right. After building the necessary appendages and attaching the servos, we found that the servos were rather big and heavy, making the front of the robot look clunky and unstable.
So, with Prof. de Leeuw's help, we found two smaller 180 degree servos and attached them as part of the arms instead of the 360 degree continuous servos. However, we had trouble figuring out how to attach a long bionicle piece to the servo horns of each of the servos without using hot glue.
The holes on the servo horns were too small for a screw to fit through, and hot glue would make the attachment permanent whether we liked it or not.
Yet, we still needed to see how the arms would behave when we run the code. Therefore, we decided to temporarily attach the bionicles to the servo horns with tape until we come up with the better solution.

Lastly, we finanlyy solved the issue with the large servo wheels that didn't fit. With the help of Phil, we screwed on the red plus-shaped servo horn to the inner side of the servo wheels so that the servo could attach to the red servo horn and hold the wheel in place.
Thankfully, the plan worked and we were finally able to use the large wheels we ordered. Of course, implementing those wheels meant that the front of the robot needed to be adjusted again so that the ball bearings could touch the ground and the RGB sensor is close enough to the ground to read the tape color properly.
So, I spend a lot of my time making modifications to the robot body once more.

### Entry by Shihan:

### Entry by Wenxuan:
I made several changes to the model because it doesn't fit with servos perfectly and is probably too thick.

In case the internal map doesn't work and the robot can't navigate back to the original quadrant, the robot would do some random turns and navigate back to the original quadrant by detecting the color of tapes on the ground. I'm also trying to implement some coarse mapping so that the robot roughly knows the relative positions of each quadrant.

Moreover, I was thinking about using RGB sensors to measure the angle/rough orientation when the robot is corssing the tapes. Josh suggested that I used to RGB sensors. By measuring time each RGB sensors is crossing the tape, the distance that each sensor travels can be recorded (proportional to the time, and we need trials and errors to find the parameter). The angle can be calculated based on the distance between the two sensors on the robot and the distance travelled by each robot, and using inverse sine we can find the angle. However, I'm not sure it's worth the effort, so I will do this the last when everything else is in place.

Furthermore, if internal map just does not work or not precise enough, we will just use RGB sensors but it has more randomness.

## Division of Labor
**Steven Park**
- Helped with Wenxuan's 3D model
- Tried to test out the newly bought parts
- Formulated plans for making the appendages grasp the block

**Wenxuan Guo**
- Worked on the full-scale 3D model
- Worked on the RGB code in case internal map doesn't work

**Shihan Zhao**
- Worked on Arduino code for the internal map
