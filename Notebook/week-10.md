# Week 10 (4/17/18 - 4/23/18)

## Progress Made:

### Entry by Steven Park:


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
