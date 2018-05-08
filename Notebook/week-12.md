# Week 12 (5/1/18 - 5/8/18)

## Progress Made:

### Entry by Steven Park:
With time quickly running out, we're working full steam towards finishing the code, which has been in a perpetual state of debugging.
Despite deciding to combine Shihan's internal map idea and Wenxuan's RGB idea, it's unfortunate for us to say that we've been encountering problems with both all week.
Despite Shihan's best attempts, several problems have been arising as a result of the internal map because it depends on the delay function in Drive.
Basically, our robot's drive function, in addition to sending out commands for the rotations of the left and right servos, take in a duration, which is supposed to dictate how long the robot maintains the given speed and direction.
The internal map relies on this Drive function to record the robot's movement so that it can find the most efficient way back to the home quadrant. However, we discovered that the duration part of Drive is unintentionally delaying the RGB sensor.
In other words, the color of the tape is not being registered by the code quickly enough, causing a major delay.
With the RGB code, there have been problems regarding storing the value for the color of the previous color tape and the current color tape.

As for me, I made my final modifications on the body to fortify the struture and make sure nothing falls apart during the competetition after a few collisions.
I also started cleaning up the main code, making it easier to read and getting rid of irrelevant functions and simplifying some elements.
So while the robot body is finished, we aren't in the clear until we have this main behavior code all sorted out.


### Entry by Shihan:

### Entry by Wenxuan:

  
## Division of Labor
**Steven Park**
- Made modifications to the body to help with holding the battery and fortifying the structure so that the front of the robot does not fall apart easily
- Cleaned Shihan's main Arduino code

**Wenxuan Guo**
- Worked on the RGB navigation code (still debugging)

**Shihan Zhao**
- Kept testing/optimizing the Arduino codes for the internal map
- Calibrated the RGB sensor
- Defined the functions for turning the arms

