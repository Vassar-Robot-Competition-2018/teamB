# Week 9 (4/10/18 - 4/16/18)

## Progress Made:

### Entry by Steven Park:
With the date of the Robot Competition looming closer, our main goal is to finish the robot so that at the very least it can find blocks and push it to the appropriate region in the arena.
However, we came across several problems this week that held us back significantly.
1. Despite the the fact that the temporary 3D printed body now prevents the servos from falling out, Shihan was still having trouble with the shaft encoders. This most likely means that we won't be able to use them very well if at all and may have to rely on a different method for the robot to find its way back to its home region. At the moment, Shihan is working on developing an internal map system for the robot so that it keeps track of its movements so that it can simply retrace this path. Unfortunately, the robot rarely moves in a straight line when looking for a block (instead it inches forward slowly), so this may be tricky.
2. The main base for Wenxuan's 3D model is complete so we went ahead and tried to print it. Unfortunately, it was a 14-hour print and the 3D printer stopped working in the middle, meaning that we may have to print it all over again. On the bright side, this has allowed us to edit some aspects of the design to improve it. However, I'm not too worried about this issue since even in the worst cae scenario, we still have the 3D printed body that I made (which is its purpose after all--to act as a functional backup plan).
3. Prof. de Leeuw brought us the large wheels we ordered so we were excited to use those instead of the small servo wheels that were currently in place. But for some reason, despite being servo wheels, these wheels ** do not fit** the servo. We have no idea why, but this unfortunately means that we may be stuck with the small servo wheels which is a problem because...
4. Shihan observed that the small servo wheels come with their own sets of problems and is having trouble with the friction against the floor. I am unsure if this means that the robot is too heavy for the wheels to move the body, but the bottom line is that not being able to use the big servo wheels we ordered has turned into a bigger detriment than we expected.

Overall, it has been a pretty tumultuous week. With time running short, we can only hope that the next week goes smoother.

### Entry by Shihan:
I'll be honest...not much progress this week. The plan was to test out my codes for the internal map, but since we switched to smaller wheels, which have worse friction than the big ones, our robot tend to drag on the ground, not moving as it was instructed to. Steven just solved this today by modifying the original big wheels to fit onto the servos, so hopefully after Wenxuan's printings are complete we can go back to more codings and testings. We also discussed a bit about the strategy we should adopt, as well as the job division. I also completed the functions for the small servos we used to drive the arms, but haven't been able to thoroughly test them. 

### Entry by Wenxuan:


## Division of Labor
**Steven Park**
- Helped with Wenxuan's 3D model
- Tried to test out the newly bought parts
- Formulated plans for making the appendages grasp the block

**Wenxuan Guo**
- Worked on the full-scale 3D model

**Shihan Zhao**
- Worked on Arduino code for the internal map
