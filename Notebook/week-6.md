# Week 5 (3/6/18 - 3/25/18)

## Progress Made:

### Entry by Steven Park:

***Before Spring Break***
With one week before Spring Break, our goal was to complete all six of the milestones before Friday. So far, we had finished four of them, so we were hopeful that we could achieve milestones 4 and 6 in time.

With milestone 6, we had to progream the robot so that it moved around the arena to all four quadrants and use the LED to signal which quadrant it was in. 
At the same time, milestone 4 required us to program the robot so that it would move towards a block and push it out of bounds.

Unfortunately, one major issue that became a problem was the limitations that arose due to the architecture of the robot. 
For one thing, our current design had the camera that was supposed to detect the colored blocks behind the RGB sensor. Not only that, the camera had to be placed very low to the ground in order for the camera to see the color of the blocks but not see color of the tape.
It is vital that the camera only detects the blocks, because the code is designed so that the robot would move based on what the camera saw. If the camera treated both the blocks and the tape the same way, then the robot would move towards the tape thinking it saw a block.
Initially, we thought that we could resolve this issue by implementing a double color system where the camer **did** detect the tape but would identify the two side-by-side different color pairing of the adjacent tapes as a single item. 
For instance, it would read "red" when it sees a red block but read something else entirely when it saw red right next to blue, like with the red-blue tape border.
Unfortunately, implementing this system in the camera proved to be more difficult than we assumed. So, we thought that placing the camera low to the ground would help the camera only see the blocks and not the tape.
This was where the limitations imposed by the architecture clashed with what we wanted. Because the camera was placed behind the RGB sensor and low to the ground, the wires connecting the GRB sensor to the breadboard got in the way of the camera.
A natural solution to this problem was to swap the position of the camera and RGB sensor, but unfortunately, the cord connecting the camera to the Arduino board was not long enough to allow us to move the camera any more forward on the robot.
In addition, when we repositioned the RGB sensor so that it was behind the camera in its current position, we discovered that the RGB sensor would detect the tape only when the robot's body was already halfway passed it.
While this doesn't really affect our task for the colored borders, it proved to be a potential problem with the white tape borders. Because the wheels were placed farther out than the camera and the RGB sensor for balancing purposes, the front half of the robot body would pass the white boundaries before it detected that it was even going out of bounds.

As a result, we were faced with a dilemma with several caveats that we tried to resolve. 
I had to redesign and rebuilt the front of the robot each time a new problem occurred with the architecture, which ended up cumulatively costing us a lot of time.
The various ways I tried to keep the camera in place without moving with each new design also took some time as well.
In addition, with each new redesign, the RGB sensor had to be recalibrated in order to properly detect each color of the tape (Wenxuan and Shihan handled the recalibration process).
According to my estimates, I must have rebuilt the front of the robot about five times in this one week.
Another problem also came in the form of the wires connecting the RGB sensors to the breadboard. These wires were sometimes loose and would often disconnect, which became a hassle to deal with. 
In addition, Shihan pointed out that the front wheels had difficulty turning and thus gave the robot turning problems. As a result, I had to replace the small wheels with ball bearings.
The "arms" of the robot also had to be redesigned so that they weren't too heavy and actually pushed the blocks as opposed to letting the blocks slide underneath and get stuck and potentially tip the robot over.

On Friday night, all three of us met in the Robotics lab to try and complete milestones 4 and 6. Thankfully, the architecture problems were temporarily resolved to allow milestone 6 to be tested.
Shihan and Wenxuan worked on the Arduino code for milestone 6 and tried different variations of it (I wrote my own version of the milestone 6 code as well but it didn't work).
Initially, we thought that it would be a good idea for the robot's default movement to travel in a large circle instead of moving straight. That way, the robot could visit all four quadrants without turning.
However, Wenxuan implemented a different idea where the robot moved randomly, hoping that this would allow the robot to visit the four quadrants much easier. Unfortunately, neither of our ideas worked as we intended.
Finally, I proposed that the robot move straight and then turn 90 degrees when it detected a white border. Thus, in one runthrough, the robot would see the white border four times, turn right four times, and visit all four quadrants as it moved along a square path.
Shihan wrote the code for this implementation, but he wasn't able to get the robot to turn exactly 90 degrees. Nevertheless, the robot turned sufficiently to the right and we were able to finish milestone 6.

Thus, the last milestone we had to deal with was milestone 4. However, this milestone required the use of the camera, and thanks to the problems I mentioned earlier regarding the architecture, there were problems with the robot moving towards the blocks.
In addition, another strange occurrence happened where the robot started malfunctioning and all the actuators stopped working. Unfortunately, much of the night was spent replacing parts, recharging the battery, etc. in order to diagnose and debug this problem.
However, in the end, we had to stop before we could figure out what the problem was. But five milestones out of six isn't bad, I suppose.

***During Spring Break***
Over Spring Break, I met with Philip Cooper, the lab's technician, and asked if he could help me with the issue that grinded our progress to a halt that Friday night. After checking the voltage of the circuitry and looking over the robot, Phil pointed over several places wheere the wires short-circuited because the metal ends of the wires were touching each other.
In our haste, we had forgotten to cover the metal ends of the wires. So, with Phil's help, I redid all the wires connected to the RGB sensor so that they were better crimped and placed in the black plastic coverings. This also ended up preventing the RGB wires from coming loose like it always did and losing connection.
I also crimped more wires to extend the camera's cable. And then, with some of the architecture limitations gone, I redesigned the front of the robot once more so that the camera was in front of the RGB sensor but the RGB sensor was still farther out in front of the two front wheels.

Here is the result of this final redesign:

![Robot Front](/Photos_and_Videos/Week6/Front.JPG)
![Robot Left](/Photos_and_Videos/Week6/Left.JPG)
![Robot Right](/Photos_and_Videos/Week6/Right.JPG)
![Robot Top](/Photos_and_Videos/Week6/Top.JPG)

While we still have to test to make sure the camera is positioned properly, I have hopes that this new design will make it easier to achieve milestone 4.
In addition, Phil let me know that it would be advisable for us to redo the soldering on the RGB sensor, which I'll leave to Wenxuan who is the only one in our group who is good at that kind of task.

In the later half of Spring Break, I met with Shihan twice to try and accomplish milestone 4 before classes started again. 
While Shihan managed to finish the code, we had a few problems with the camera detecting both the tape and the blocks when it should only be detecting the blocks.
We tried several solutions such as covering the bottom half of the lens of the camera, but this did little to help. 
We also noticed that the robot was dragging at times and having difficulty moving. There were two main reasons for this.
First, the ball bearing at the back of the robot was lifting the robot slightly higher up than it was supposed to, giving the wheels less friction than normal. After some consideration, we ended up removing the ball bearing entirely since given the robot's current design, it could balance itself just fine.
Second, the servos we attached with tape and held down with legos were starting to come loose. This goes to show the urgency of printing a 3D model base. At the moment, we managed to temporarily solve the problem, but we need to find a way to attach the servos firmly to the robot.
Ideally, we should spend the second 6 weeks on our 3D model, but a good alternative is to cut a large square hole in the foam base of the robot and hold the servos down on the base using clamps.
For right now, we still managed to get milestone 4 accomplished by the second day. 


### Entry by Shihan:


### Entry by Wenxuan:


## Division of Labor
**Steven Park**
- Repeatedly rebuilt the architecture of the robot multiple times in attempts to achieve milestone 4 & 6
- Worked on Arduino code for Milestone 6
- Replaced the front two wheels with ball bearings
- Met with Phil to work on crimping, circuitry, and miscellaneous building techniques (Spring Break)
- Redesigned the front of the robot to position the RGB sensor behind the camera (Spring Break)
- Crimped extra wires to extend the camera cables (Spring Break)
- Made modifications to the robot body to accomplish milestone 4 (Spring Break)

**Wenxuan Guo**
- Worked on Arduino code for Milestone 6
- Helped with redesigning the robot
- Recalibrated the RGB sensor multiple times
- Replaced some of the faulty wiring

**Shihan Zhao**
- Worked on Arduino code for Milestone 6
- Worked on Arduino code for Milestone 4
- Recalibrated the RGB sensor multiple times
- Worked with the camera
- Finished the Arduino code for Milestone 4 (Spring Break)
- Recalibrated the camera and RGB sensors (Spring Break)