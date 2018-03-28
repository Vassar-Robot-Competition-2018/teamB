# Week 5 (2/27/18 - 3/5/18)

## Progress Made:

### Entry by Steven Park:

We finally have our Team Name: **Team Renegades**

The name was mostly inspired by the fact that the final design of our robot looks oddly like a Jeep SUV. But I also suggested it because I really like the X Ambassador song.

[Team Theme: Renegades by X Ambassadors] (https://www.youtube.com/watch?v=8j741TUIET0)

Our team got a tremendous amount of work done this week. After finisheding Milestone 2, we went full steam and finished two more milestones. 
The first one we got done this wek was Milestone 3, which was entirely thanks to Shihan. Since he knew the ins-and-outs of the camera and RGB sensor after working with them for so long that he volunteered to work on the task and actually got it done.
The second milestone we finished was largely due to Wenxuan, who stepped up with the Arduino code and spent a lot of time debugging it. 
The code for Milestone 5 did have some hang-ups and Shihan and I helped with this code as well. 

At one point, we were stuck because the robot could either signal with region it was in and could move forward but for some reason, it couldn't do both.
This obstacle took some time to figure out and I had to configure the height of the RGB sensor appendage while Shihan repeatedly recalibrated the RGB sensor thresholds.
Thankfully, we got the code to work in the end (Instead of putting the RGB sensor function and the Drive function in the loop together, we incorporated the Drive function in the RGB sensor function so that the Drive function was the default behavior until the RGB sensor threshold was reached).
Technically, Milestone 5 haven't been approved yet but we figured that all the robot needed to do to achieve Milestone 5 is to signal what region it started in. 
So, we programmed the robot so that it moves forward until it sees a colored tape, which would then trigger a subroutine to light up the LED to an appropriate color and drive backwards into the region it started in.
We just placed the robot in one region, turned it on, saw it identify the region with the right color, turned the robot off, and repeated the same steps in a different region.


```
void RGB() {
  int counter = 0;
  
  while (counter < 2) {
    uint16_t clear, red, green, blue;
    tcs.getRawData(&red, &green, &blue, &clear);

    Drive(10,10,1);	//Added the Drive function here
    
    if (red > 1500 && green < 1500 && blue < 1500) {
      setState(255, 0, 0);
      setColor2(STATE_RED);
      counter++;
    } else if (green > 3000 && red < 3000 && blue < 3000) {
      setState(0, 255, 0);
      setColor2(STATE_GREEN);
      counter++;
    } else if (blue > 3000 && red < 2000 && green < 4500) {
      setState(0, 0, 255);
      setColor2(STATE_BLUE);
      counter++;
    } else if (red > 3000 && green > 2000 && blue < 3000) {
      setState(255, 255, 0);
      setColor2(STATE_YELLOW);
      counter++;
    } else if (red > 4000 && green > 4500 && blue > 4000) {
      setColor2(STATE_WHITE);
      EscapeBack();
    } else {
      setColor2(STATE_NULL);
    }
  }

  while (counter >= 2) {
    Drive(-30, -30, 50);
    STATE = PREVIOUS;
    setColor2(STATE);
  }
}
```

I mostly spent the week remodeling the robot and building all its necessary appendages. 

![Robot Front](/Photos_and_Videos/Week5/Front.JPG)
![Robot Left](/Photos_and_Videos/Week5/Left.JPG)
![Robot Right](/Photos_and_Videos/Week5/Right.JPG)
![Robot Back](/Photos_and_Videos/Week5/Back.JPG)
![Robot Top](/Photos_and_Videos/Week5/Top.JPG)

Using both Legos and Bionicles, I built a front appendage that not only held both the RGB sensor and the camera firmly in place but also had "arms" that funnelled any block in front of it to the front of the robot.
According to Shihan, the size of the color block that the camera detects is vital for the robot to know how close the block is to the robot, so this was a necessary feature.
I also had to adjust the height of the RGB color sensor holder several times because that sensor really only works when it's right above the ground.

Unfortunately, we decided to not use the line-detecting sensor. The RGB sensor was working very well by itself and the line-detecting sensor didn't really serve a purpose anymore.
Initially, I thought it might be useful to keep it so that the robot has a back-up sensor in case the RGB sensor malfunctioned, but the line-detecting sensor can't even tell the difference between the colored and white lines and was just taking up space.

The camera also had a problem where, despite it being designed to **only** identify blocks, it would pick up the colored tape at close range. 
Initially, we thought we could solve this problem by having the camera identify two-colored objects as tape, but this proved to be much more difficult than we thought. 
So instead, I came up with a more embodied solution where I would have a piece of Bionicle slightly cover the bottom of the camera. Since the camera is already placed so close to the ground, blocking a sliver of the camera's view alleviated this problem.

One of the main adjustments I made to the robot was the addition of two more wheels. After observing that the robot tended to tip backwards and forwards whenever it moved since it only had two wheels to balance the body, I thought it was apt to add more wheels to distribute the weight more evenly.
These two wheels aren't attached to a servo motor, but they help hold up the front of robot, which was incredibly helpful especially considering how front-heavy this robot was. As a result, the design of the robot strayed away from the two sided vehicle we originally imagined to that of a Jeep SUV.
I also added a more sturdy frame and support to the front so that it would be less likely for it to accidentally fall apart. I also made a back appendage to not only push blocks away when the robot moves backwards but also to hoold the battery cable and switch.

Most importantly, I discovered a really cool hidden advantage to using Bionicles to build the bulk of the robot: the holes in the Bionicles are perfect to thread wires through and keep them in place.
So I threaded the wires connecting the RGB sensor to the breadboard through several of these Bionicle holes, making the robot look even more like a Jeep vehicle.

We're finally approaching the last week of RC work before Spring Break. I think we're in a good position right now. We have a set plan set up for accomplishing both Milestone 5 and Milestone 6 that hopefully we can accomplish during the lab.
For Milestone 4, we'll program the robot so that it finds a block and then it moves forward to find a colored tape. Upon finding a colored tape, it will immediate turn 180 degrees and move straight since the white tape is right across the colored tape. Then, it'll stop in front of the white line and the block will fall out of bounds since the arms of the robot are more further outwards than the RGB sensor.
For Milestone 6, we're thinking of programming the robot so that it's default "forward" movement actually has a small curve to it. That way, the robot should visit all four regions in one big circular motion. The RGB sensor has been calibrated so we can simply program the LED to signal the color of the region as the RGB sensor identifies the color of the tape.

In the long-term, we still have to think about 3D printing and buying a large wheel set because my greatest concern right now is that the big wheels we superglued on the Servo wheels may fall off eventually. But so far, the wheels have held, suprisingly.
But we still have to handle this vehicle prototype with care.


### Entry by Shihan:
Much of the time this week had been spent on recalibrating the RGB sensor. It turned out that even the slightest change in height could mess up it's performance...We used a set of thresholds for Red, Green, and Blue color components as indicators of color. When we lifted the RGB sensor higher from the ground, the color signals weakened, and thus the original thresholds would no longer work. We learned to be extremely careful with readjusting the height of our robot. We also had small discussions on what other sensors or tools we should implement on our robot. We've always been having trouble with distinguishing between color boundaries and color blocks, so Steven suggested using a pair of IR sensors in conjunction with pixy camera. Personally, I'm slightly doubtful because IR sensors had short sight, but I still think they will be a good solution if we only use them for short range -- we'll have to experiment. I'm increasing inclined towards the idea of building an internal map because we would eventually need the robot to push a block back to its starting quadrant. (I guess defining a default movement that covers the evntire arena and having the robot simply drop the block when it detects the right color boundary could be a solution, but this shouldn't be relied upon due to its inefficiency -- just think about all the distance it has to travel before returning to its starting quadrant!) We confirmed that the robot will always start at the center of one of four quadrants, facing inwards towards the center of the arena, and I think this is definitely a rule we can exploit! For a start, the robot can easily save the distance and direction it has traveled and return to its starting quadrant efficiently, which is already a considerable advantage to begin with. In addition, we can use color boundaries as further clues and potentially save hold to get to all four quadrants, but the implementation of this function will not be easy. 

### Entry by Wenxuan:
Milestone 5 was easier than milestone 4 and 6 so we decided to finish this one first. Since RGB only worked when it was sufficiently close to the objects, we put the RGB very close to the ground. The sensor was fast enought to identify the color boundaries adjacent to each other, so I decided to include two state, PREVIOUS and STATE, to track the color of previous quadrant and current quadrant. When the robot crossed the broundary, it will record PREVIOUS and STATE. In order to signal the state it was in required by milestone 5, as soon as the robot crossed the boundary (by using a counter, when it reached 2, it meant the robot just crosse a boundary consisting of two colors), it would back up and change the state back to PREVIOUS and signal the color of the quadrant using LED. 

I modified some functions in the RGB-sensortesting file, because after adding setState, the setColor2 passing three parameters is very redundant and inefficient to use. Therefore, I modified setColor2 to pass only one parameter, the STATE that the robot was in. 

I ran into trouble when I put the drive(30,30,1) and RGB() functions in the loop because it seemed that the loop was not executing the RGB function when the robot was driving. So Steven moved the drive() function inside the RGB() method and it workd. 

## Division of Labor
**Steven Park**
- Finished the construction of the robot
- Helped with the Arduino code for Milestone 5

**Wenxuan Guo**
- Wrote and finished the Arduino code for Milestone 5
- Modified the RGB sensor code (added setState and modified setColor2)

**Shihan Zhao**
- Wrote and finished the Arduino code for Milestone 3
- Repeatedly calibrated the RGB sensor for Milestone 5
- Helped with the Arduino code for Milestone 5
