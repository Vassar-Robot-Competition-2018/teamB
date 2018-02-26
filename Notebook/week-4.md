# Week 4 (2/20/18 - 2/26/18)

## Progress Made:

### Entry by Steven Park:

At long last, we achieved our second milestone (milestone 2).

For this week, our primary goal was to get all the milestones done as quickly as possible before Spring Break. As a result, we put the 3D printing on hold and focused on implementing only one side of the robot first.
Although...after testing how the robot moved and reacted to the tape, we might not really need to make this robot double-sided. 
When the servos change directions in the complete opposite direction, the robot doesn't back up normally like a car--it turns around and then moves...Odd.
I also keep forgetting but we really need to come up with a team name and a name for the robot. I'm not exactly creative enough to come up with one so I'll leave that up to my team members.

In any case, a lot of good news this week. Most of the problems I encountered with the Arduino board disappeared, so I had no trouble uploading the code from my laptop.
I spent most of my week working on the line-detecting sensor so that we could get milestone 2 out of the way. After Wenxuan sautered the sensor, I continued working on the Arduino code to test it out so that the robot would move forward when the IR sensor wasn't active and move forward whenever the IR was active.
As mentioned last week, the IR sensor is terrible at telling the difference between white tape and the other colored tape, so the sensor became active when it sensed **any** colored tape.
My main focus was on solving the strange signal-clashing behavior of the robot, so I sunk a lot of time working on that aspect of the Arduino code. However, the biggest obstacle for me was that we haven't yet built the robot component that would hold onto the IR sensor and point it towards the ground and the wires on the IR sensor were not long enouogh to reach the Arduino board.
Without the IR sensor properly affixed onto the robot, it was clear that my attempts at testing the IR sensor code would continue to go to waste (previously, I would hold manually hold the IR sensor and point it towards the ground to control the robot's actions).
So, I tried my hand at crimping some wires so that we could extend the IR sensor wires. Unfortunately, crimping is **so** much more difficult than sautering (which is already pretty hard). 
Thankfully, Wenxuan had more expertise with crimping, so she spent much of the lab crimping several wires on my behalf. By the end of the lab, she had crimped 8 wires on both sides, giving us enough wires to hook up both the IR sensor and the RGB camera to the Arduino board.

Shihan may have to correct me on this, but I believe he was working on the Arduino code for the LED since two of the milestones require the robot to give a signal when it sees a specific color. 
He may have also worked on the Arduino code for the IR sensor as well. Nevertheless, thanks to him, I think we have all the Arduino code required to use all the various sensors that we have. Now all we need is to connect them to the main code.

On Saturday, we met together to work on the robot for several hours (we have done this every Saturday since the semester started). The first thing I did was build the parts of the robot that would not only hold the IR and RGB sensors but also the "arms" that would allow the robot to push the blocks. 
While I was initially worried that I would not find the Lego/Bionicle parts I needed, I was surprised to find all the parts with relative ease. After spending some time constructing the parts, we're starting to see the robot finally take shape. 

![Robot Front](/teamB/Photos_and_Videos/Front.jpg)
![Robot Left](/teamB/Photos_and_Videos/Left.jpg)
![Robot Right](/teamB/Photos_and_Videos/Right.jpg)
![Robot Back](/teamB/Photos_and_Videos/Back.jpg)
![Robot Top](/teamB/Photos_and_Videos/Top.jpg)

I also found a way to attach the IR sensor to the robot without using any tape or glue of any kind, which is nice.
With the modifications complete, I went ahead and calibrated the IR sensor by observing how the robot behaved, using the same code where the robot moves backwards only when it senses tape.
As it turns out, the robot performed much better now that the IR sensor was actually affixed to the robot. It took a couple tries to get the height of the IR sensor placement right, but ultimately I managed to figure all that out.
And as one big cherry on top, I ran the Arduino code for milestone 2 and the robot achieved it. However, it's important to note that the robot turned around when it came across *any* colored tape, but that doesn't matter--the RGB sensor will fix that.
And like I mentioned earlier, I do not know why the robot turns when it senses the tape instead of moving backwards. Maybe that's just how the servos function. However I have noticed that the robot sometimes perform its "turning" behavior even when it doesn't detect any tape, which worries me a bit.
Perhaps I have to spend a bit more time recalibrating the sensor ~~or maybe sensors just suck in general~~.

Now, the goal is get the rest of the milestones down. The third milestone requires the robot to move towards a colored block and stop in front of it and signals that it has found a block. 
This means we have to work on connecting the code for the camera to the LEDs. I experimented with that a bit this week, but as expected, it wasn't as easy as I expected. 
However, Shihan volunteered to work on the code for milestone 3 since he has spent much more time than me or Wenxuan on the code for both the camera and the LED. In any case, that means Wenxuan and I have to work on the code for the other milestones.
With only two weeks left, we are starting to get pressed for time. We need to make fast progress **now**.


### Entry by Shihan:


### Entry by Wenxuan:



## Division of Labor
**Steven Park**
- Constructed the arms for the robot and modified the body a bit
- Constructed the segment of the robot that will hold the IR line-detecting sensor the RGB color sensor
- Worked on the Arduino code for the line-detecting IR sensor for milestone 2 and accomplished milestone 2

**Wenxuan Guo**
- Worked on crimping both ends of the twelve wires required to connect the line-detecting IR sensors & RGB color sensors to the Arduino board
- Worked on the Arduino code for the RGB color sensor

**Shihan Zhao**
- Worked on the Arduino code for the LED so that it will signal a new color when the robot detects white tape
- Worked on the Arduino code for the RGB color sensor
