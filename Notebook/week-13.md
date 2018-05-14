# Final Week: Week 13 (5/9/18 - 5/14/18)

## Progress Made:

### Entry by Steven Park:
With this being the last week to work on the robot before the semester, we were in a very difficult situation. For the past several weeks, our group has been plagued with nothing but errors and problems that continued to hinder our progress significantly.
At this point, seeing how we haven't even implemented the code for the robot to pick up a block and move it to its home region properly, we were in a desperate state. So, this entire week, we spent all our time working on our robot (Although I can safely say that our group is most likely the the group that spent the most time on this project throughout the entire semester).
While part of the problems was the endless number of debugging that needed to be done, the other major factor that led to this situation was our overambitious goals and hang-ups on "perfect" behavior.
We were too focused on implementing precise, error-free behavior for our robot that we ended up overcomplicating the design and wasting a lot of time chasing ideas that were going to be near impossble to implement given our time limit.
So, significant adjustments were made to our robot's design so that we could at the very least have a working model.

First and foremost, we nixed the internal map that Shihan spent a whole bulk of the second half of the semester working on. It was a really cool idea--having the robot retrace its steps so that it returned to its home quadrant without meandering about randomly and wasting no time at all.
However, our first attempt with the internal map didn't work because the shaft encoders were not accurate enough and too difficult to attach to the robot, and our second attempt led to problems with the RGB sensors that caused them to delay detecting the colored tapes.
We did our best to work around these bugs, but ultimately, given the lack of available time, we decided to not use internal maps. However, if there is time, Shihan is very adamant on attempting to implement it somehow. But I am of the opinion that it would be for the best if we didn't use internal maps at all.
So instead of the internal maps, we ended up using RGB sensors like all the other groups. Thankfully, Wenxuan has been working on the code for returning to home using the RGB sensors, so we weren't starting from scratch.
What I did next was sort of blend Shihan's internal map idea with Wenxuan's RGB code to create a system where the RGB creates a very simple internal map using inputs from the RGB sensor.
In essence, since the orientation of the colored regions in the arena will always stay the same (the green region is next to red and yellow, the yellow region is next to green and blue, etc.), I created variables called RegionA, RegionB, RegionC, and RegionD.
RegionA will hold the color of the home quadrant, RegionB will hold the color of the left adjacent quadrant, RegionC will hold the color of the right adjacent quadrant, and RegionD will hold the color of the quadrant diagonal from the home quadrant.
Initially, these variables will be blank. But once the robot moves and identifies the color of the quadrant it started in, it'll assign the appropriate colors to each region depending on the color of the home quadrant.
This works since, for example, we know that if the home quadrant is red, the left adjacent quadrant must be yellow. Using this system, we can program the robot to perform certain tasks based on the color of the quadrants without coding for every possible combination of situations for each home quadrant color.

As we tried to accomplish the remaining five milestones in one week, we came across two headache-inducing problems with the robot. First, the dt function that looks for specific blocks using the camera was not working as it should. Second, the RGB sensors were detecting the correct colors of the tape when the robot was stationary but failed to process any colors when the servos were moving.
We spent an agonizing amount of time trying to figure out what was causing these two problems (it didn't help that we were debugging in the midst of other groups having much success with their own robot).
We tried a lot of different solutions. We triple-check the calibrations of the camera and the RGB sensors, modified the code to not include the internal map, and made various other changes to the Arduino code. 
I assumed that the problem with the RGb was caused by the delay statements in the Drive function, so I attempted to rewrite the code and use millis() instead, but that led to no results.
However, after a long time, we managed to figure out how to solve both problems. The problem was dt was solved by adding a delay function inside and that **somehow** fixed the camera. As for the RGB, it turns out that the RGB was so sensitive that the values of the color tapes were different the root was moving compared to when it was still.
As a result, we modified the RGB calibrations and extended the range for each color so that the RGB could detect the color even when the robot shakes as it moves. We also discovered that the structure of the front of the robot became loose as the robot moved, which contributed to the offness of the RGB calibrations. So, I made changes to the body yet again so that nothing does come loose.

Finally, Shihan, the MVP of this project, managed to combine everything together to create the main code using the RGB system instead of the internal map. And to our relief, the robot was able to find blocks and pick them up.
From there, we spent the rest of the night (until 5 am on Saturday) modifing both the body and the code to increase the accuracy of the robot's behavior and account for all the things that could go wrong, suh as a block getting stuck underneath the arms and lifting the robot up.
We changed the EscapeBack feature so that the robot wouldn't end up stuck in a loop of escaping the boundaries only to run straight into it, raised the arms a bit off the ground, added claw-like hands to better hold the block, programmed the robot so tha it didn't pick up any blocks that matched the color of the home quadrant when it's in the home quadrant, and so on.
As a result, we were able to accomplish a few of the milestones. Hopefully, we can get all of them done by monday.

**The Final Design of the Robot Body**
![Final Design](/Photos_and_Videos/Week13/Final_Body.JPG)

***Update (5/14/18 @ 1:00am)***
After what seems like forever, we have finally accomplished all the milestones. Several more changes were made to both the robot body and the code. For instance, we moved the side RGBs closer to the front because too much of the body was going past the white tape before EscapeBack was triggered, which caused the robot to get stuck.
We also constructed a stopper that held the block close to the body of the robot to prevent the block from coming loose and slipping underneath the arms during EscapeBack.
In addition, we added line-detecting sensors to the front of the robot so that the robot only returns home when the line-detecting sensor actually senses a block in its grasp.
Minor adjustments also have been made such as modifying Drive so that the robot moves in a straight line. Many calibrations were also performed for both the camera and the RGB sensors since they seem to be affected by the smallest possible things.

### Entry by Shihan:


### Entry by Wenxuan:

  
## Division of Labor
**Steven Park**
- Made multiple changes to the body of the robot (fortifying the front to keep it from coming loose and messing up the RGB calibrations, modifying the arms to grab blocks better, & changing the orientation of the camera so that it could see out farther).
- Wrote the RGB homing function that combined Shihan and Wenxuan's ideas together to create a system that would direct the robot back home by creating a simple internal map using the RGB sensors.
- Tried to write code that would replace the delay statements in the main code.
- Helped with debugging the code.
- Cleaned up the Master Code

**Wenxuan Guo**
- Helped with modifying the body of the robot
- Helped with debugging the code
- Worked on the RGB code
- Tested the rest of the milestones
- Worked on implementing the line-detecting sensors so that the robot makes sure that it's actually holding a block before returning to home region

**Shihan Zhao**
- Worked on the bulk of the coding, writing the main code and driving the debugging process
- Implemented all the changes to the robot code-wise with each runthrough, updating the code after observing the problems that emerged with the robot's behavior.

