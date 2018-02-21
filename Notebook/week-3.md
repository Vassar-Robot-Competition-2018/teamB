# Week 3 (2/13/18 - 2/19/18)

## Progress Made:

### Entry by Steven Park:
Having reached the quarter-way point for this course, it's important that we make steady progress with completeing the six milestones due before Spring Break.
While we've reached milestone 1 very early on, we are still having trouble trying to accomplish the other milestones, mainly due to unexpected actuator behavior and code errors.

For this week, Wenxuan sautered the line-detecting sensor (as well as an extra later in the week) so that we could start exploring how the code worked with that sensor.
Most of my time was spent trying to figure out the line-detecting sensor and calibrating it, mainly because a large number of our milestones relied on this sensor.
After countless computer errors and forced shutdowns, I finally managed to figure out how the sensor worked and managed to calibrate it.
However, I discovered that the line-detecting sensor detects the presence of the white tape in just the same way as the other colored tapes. 
We had hoped that there would be enough of a difference so that the line-detecting sensor could easily identify the borders of the arena, but it appears as if it won't be that easy.
Thus, we decided to write the code so that the robot will know that it has reached the border only when the line-detecting sensor is active **and** the camera *doesn't* identify the colors red, blue, green, or yellow.
That way, the robot will know that the tape in front of it is the white tape. We are also thinking of using the close-range RGB camera and placing in on the front of the robot. 
Then, the Pixy camera will identify colors at a distance while the RGB camera double-checks close-up. 

Unfortunately, we've came across several problems hooking up the line-detecting sensors to the two servos. We wrote a simple code so that the robot moves backwards whenever the line-detecting sensor is active and moves forward otherwise.
However, actually testing the robot showed other results. While the servos moved as we wanted when we brought the tape closer and farther away from the line-detecting sensor, actually placing the robot in the arena led to more inconsistent outcomes.
The servos would move backwards whenever it detected the white tape, but the gray area that covers the entire arena would cause the servos to jerk forward and backwards as if the two signals were clashing.
At first, we thought the line-detecting servos were too sensitive, but the thing is, this problem would still persist even when we decreased the sensitivity of the sensor dramatically. It seems the gray placemats muddles the sensor somehow so that the robot switches between moving backwards and forwards rather than reliably moving forwards.
This issue will probably be a huge headache to come next week, especially since we're desperately trying to finish milestone 2. Speaking of errors, my laptop is now continually having trouble identifying the Arduino port whenever I try to upload my code to the Arduino board.
I worry that this problem may worsen and I won't even be able to upload the code from my laptop anymore.

Shihan spent most of his time on the LED lights since those are involved in the milestones as well. However, we needed specific resistors for setting the resistors up and we couldn't find the resistors we needed. ~~Quite the robotics lab we have here.~~
He also worked on trying to write the code for a toggle-switch so that we could turn the robot on and off manually. However, for some reason, Shihan seemed deadset on establishing the switch in a way that doesn't only stop the code but also prevents the robot from wasting its battery ~~which I personally feel like is an unnecessary issue at this point in time~~.
So, after having trouble with the code for a regular toggle switch, he wrote the code for an on-and-off button. But unsurprisingly, we couldn't find a button anywhere even though I'm sure I've seen it lying around somewhere.
He also needs resistors for the button but like I stated earlier, the lab doesn't seem to have a reliable supply of common wiring materials. So he moved on to helping me with the line-detecting sensor and he came across the same trouble I faced with the inconsistent servo activity (or maybe it's sensor activity).

Of course, all the work on the line-detecting sensor and servos are useless if the robot body is too heavy for the small wheels to even move it. So I spent a couple hours not only trying to write the Arduino code for the main loop but also finishing the Robot body.
Using the Lego and Bionicle parts I found in the bins, I fortified the frame (a process which I had to repeat two or three times due to unexpected design flaws) and Wenxuan used hot glue to attach the big wheels we found to the smaller wheels we have.
Unfortunately, even after being careful, Wenxuan and I discovered that even hot glue seems to have trouble keeping the big wheel attached. Handling the robot too roughly caused the big wheel to fall off, so we had to repeat the hot glue process several times as well. 
It was only after I finished the robot body that I made my last endeavor with the hot glue gun and got the big wheels to stick. Although I'm worried that the friction on the wheels would cause them to fall off again. Superglue may be our only option.

At the moment, finishing the milestones is our top priority, so our prototype ended up being only a one-front robot rather than the two-front robot we originally designed. I also didn't spend much time on the 3D printing since that can come later.


### Entry by Shihan:
It has been a frustrating week for me...not much solid progress had been made this week. I mainly worked on three tasks -- adding a RGB LED, adding a switch that turns the robot on and off, and expermenting with color codes. I eventually got the LED to work, but only after two hours of debugging and not without help. Switch was a hard one, because I was trying to implement it by putting Arduino to sleep mode with codes, which involves all sorts of complications such as attaching/detaching interrupt, pin, circuit connection. In the end I built the switch circuit and codes that could turn Arduino off -- temporarily (because it doesn't stay off). Before I could solve this Steven found a physical switch soldered to the battery cord that simply cut the power, which we immediately turned to for its reliability. With some help, I also figured out the inner workings of color code, so now our camera can distinguish between color boundaries and blocks.

Perhaps I need to seriously consider the viability of a component before I get to it. I've been spending too much time on parts that might not eventually be used on our robot. (My fellow teammates, if you are seeing this, I sincerely apologize for my stubborness...)


### Entry by Wenxuan:


## Division of Labor
**Steven Park**
- Worked on the Arduino code for the line-detecting IR sensor
- Worked on the main code and tried to combine the code for the camera with that of the line-detecting sensor
- Worked on testing the robot to accomplish milestones 2 & 3
- Completed the robot body of the prototype by fortifying the frame and attaching the large wheels

**Wenxuan Guo**
- Sautered all the necessary materials (the other line-detecting sensor & the RGB camera)
- Worked on the Arduino code for the servo that will act as a camera stand
- Helped complete the robot body

**Shihan Zhao**
- Worked on the Arduino code for the camera and IR sensors
- Worked on testing the robot to accomplish milestones 2 & 3
- Worked on the Arduino code and circuits for the toggle switch and LED lights
