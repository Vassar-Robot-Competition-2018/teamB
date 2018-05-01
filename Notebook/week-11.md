# Week 11 (4/24/18 - 4/30/18)

## Progress Made:

### Entry by Steven Park:
With only a few days left until the robot competition, we entered the stage of robot building where we focused on finalizing both the design and the code.

In regards to the body, I finally found a way to attach the bionicle pieces to the servo horns to act as the forearms that hold onto the block.
First, I used the sautering iron to carefully melt two holes big enough to fit the screws I found in each of the servo horns.
That way, I could hold the bionicle piece to the servo horn using a screw and nut combo. After a few attempts trying out different orientations for the arms, I finally arranged the arms so that when the move inward to hold the block, the ends of the arms touched and the arms themselves created a pointed end to push away other blocks.
I also continued making more improvements to the robot body using bionicle pieces. For instance, I added attachments to better hold pieces in place so that the front has less of a likelihood of falling apart.
Upon Shihan's request, I also made changes to prevent the RGB sensor from shaking so much when the robot moved, adding reinforcements so that the RGB could properly read the colors it detected.
Finally, concerned that the battery may fall off the top of the robot due to the lack of room, I made a makeshift fence to hold everything on the top of the robot in place.
However, the biggest design change was the decision to add two more RGB sensors. Upon observing the robot moving randomly in the arena, we discovered that the placement of the sole RGB sensor in the middle of the front of the robot make the robot vulnerable to getting stop along the edges of the arena. 
Forced with no other choice, we decided to attach two more RGB sensors farther out on the front of the robot to detect the white tape before the center RGB. 
These two RGB sensors are designed to only see the white tape. While Shihan and I initially had difficulty implementing two more RGB sensors to the Arduino, we managed to figure out how to get them to work thanks to the i2c library.

Here is the final design of the robot body, which has changed significantly over the past several weeks.
![Front](https://github.com/Vassar-Robot-Competition-2018/teamB/blob/master/Photos_and_Videos/Week11/Front.JPG)
![Left](https://github.com/Vassar-Robot-Competition-2018/teamB/blob/master/Photos_and_Videos/Week11/Left.JPG)
![Right](https://github.com/Vassar-Robot-Competition-2018/teamB/blob/master/Photos_and_Videos/Week11/Right.JPG)
![Back](https://github.com/Vassar-Robot-Competition-2018/teamB/blob/master/Photos_and_Videos/Week11/Back.JPG)

In regards to the code, since time was quickly running out, we were focused on finishing the main code for the robot, the one we would implement in the robot for the competition. 
In the beginning, all three of us came up with an idea for the basic structure of the code and what type of behavior pattern the robot would perform.
Shihan believed that the internal map would be the most effective in bringing the target block back to the home region. Wenxuan thought that it would be easier to use the RGB sensors to keep track of the location of the robot by storing what color the RGB sensor detected previously and what it detects currently.
I personally thought that the easiest and most efficient solution would be for the robot to use the camera to find its way back to the home region instead of any kind of internal mapping system. 
The way I imagined it was that the robot would search for the block by looking for a colored object that's smaller than a certain size parameter and then once it needs to return the block to the home region, it could use the camera to find a colored object that matches the color of the block yet bigger than the block.
In essence, the robot would be able to differentiate between, say, a red block and red tape by the difference in size. Unfortunately, I suddenly realized that my idea would not work because once the robot is holding the block and needs to return to the home region, the block would block the camera vision, preventing the camera from seeing anything, much less the tape of the home region.
So, we decided to combine Shihan and Wenxuan's idea together. The robot will use the internal map as its default strategy **but** use the RGB sensors to double-check and make sure that the internal map is working properly.
For instance, if the robot reaches the end of its internal map path and yet the RGB sensors do not detect the appropriate colored tape of the home region, then the robot would know that the internal map messed up and proceed to carry out a different subroutine to reset the internal map.

### Entry by Shihan:

### Entry by Wenxuan:
I worked on the backup plan if the internal map doesn't work, and there will be more randomness in the internal code because the only environmental cues we are using is the tape on the ground and the robot only gets the cues when it crosses the tapes.
Here's the variable list:
int QUADRANT = 0; //the home quadrant
int previous = 0;  //the previous quadrant it's in
int current = 0;  //the current quadrant it's in
int RED = 1;
int GREEN = 2;
int BLUE = 4;
int YELLOW = 3;
int counter = 0;

1)set QUADRANT: set the original quadrant
  First (the robot turn around 45 degrees and) start driving forward to cross the tapes. The RGB() function is embedded in the Drive function, so the CURRENT (quadrant) and PREVIOUS (quadrant) variables are constantly updated. 
  Using the RGB() function with a counter (= 0), as soon as the counter added up to one, set QUADRANT = CURRENT.
  Then the robot will use its camera to find blocks and pick it up.

2) after picking up a block
When the robot picks up a block, it will drop the block if the current quadrant corresponds to the original QUADRANT. 

We have no clue about the robot's orientation in the current quadrant, so we don't know whether making it go back in a straight route means going back to the PREVIOUS quadrant, or turning 90 degrees means going to the next quadrant. Therefore, we roughly correct its orientation by first letting it crosses another tape boundaries. And after crossing another boundary (using counter to check), we can make it:
  a)Drop the block if CURRENT = QUADRANT (the original quadrant).
  b)Go back in a straight route if PREVIOUS = QUADRANT. this is kind of redundant, because the robot should have dropped the block previously, but just to make sure if there's an error. 
  c)if the QUADRANT is in a diagonal relation with the CURRENT quadrant, the robot turns 90 degrees twice (and crosses the tapes twice). I set the constant for each quadrant in a special way, so that if the target quadrant is in the diagonal, addition of the two quadrants = 5. This is just to simplify the code, so we don't have to hard code for each specific quadrant (or else we have to code four conditional statements for each equadrant, 16 in total. but in this case, we only have ot code four conditional statement for all the quadrant).
  
![relation](https://github.com/Vassar-Robot-Competition-2018/teamB/blob/master/Photos_and_Videos/Week11/Relations.PNG)
  
  the direction of turning (either left or right) depends on the relation function that I'll explain below(in (3)).
  d)else it means the QUADRANT is the next to the CURRENT (but it's not the PREVIOUS), the robot will turn 90 degrees once.

3)the relation() function. This is the part where we need to hard code.
  int relation(){
    //1 = turn right; 2 = turn left;
    int Direction; 
    if ((previous == RED && current == GREEN) || (previous == GREEN && current = YELLOW) 
    || (previous = YELLOW && current = BLUE) || (previous = BLUE && current = RED){
      return Direction = 1;
    } else return Direction = 2;
  }
  
  Moreover, since the 3D printer won't corporate, we will just stick to the prototype we have and focus on the code
  
## Division of Labor
**Steven Park**
- Finished building and attaching the arms to the robot
- Modified the robot body to increase stability and reduce shaking, improve balance, and prevent parts from falling off
- Helped with crimping 8 wires for the RGB sensors

**Wenxuan Guo**
- Worked on the RGB sensor code for backup
- Crimped 8 wires for two other RGB sensors

**Shihan Zhao**
- Worked on the internal map
- Worked on the Arduino code and wiring that allowed the use of three RGB sensors
