# Week 1 (1/30/18 - 2/5/18)

## Progress Made:

### Entry by Steven Park:
For the first week, there were two main goals for our group: 
1. Establish a basic design (shape, wheels, sensors, actuators, etc.) for our robot.
2. Start building the prototype so that, at the very least, it can move forward.

In regards to the design, we brainstormed several ideas:
- A rectangular shape for the body with two levels; the bottom will hold the battery and the servos for the wheels and the top will have the Arduino board and camera
- Larger wheels may help with more efficient travel and balance
- Camera facing forward rather than down and fixed to an L-shaped braket of some kind

In regards to the arms that will transport the block, we decided to have a wide, two-pronged, boxy appendage at the front of the robot.
This appendage will be static and the prongs will be wide enough to fit in one block with some extra space but narrow enough so that two blocks can't fit inside.
The idea is that the robot will use both its camera and its IR sensors to identify and approach a block of the desired color.
As it moves into the block, the block will be caught within the long prongs of the appendage. 
The robot will then **push** the block to the required destination (perhaps program the robot so that it moves forward whenever it senses the desired color and will eventually reach the desired location. It can then identify the tape, move a fixed number of steps forward, and then move backwards and turn 180 degrees).
While this design doesn't involve any fancy mechanisms or motors, a simple approach may prove to be the most pragmatic.
However, we may end up changing out plan if there's pushing the blocks causes too much friction. ~~But I really doubt it.~~

On the building aspect of the project, things were...more *difficult* than I had previously assumed.

The biggest hassle turned out to be the Arduino code, which I was primarily working on. 
The first goal, obviously, was to get the two servos to move in the same direction at the same speed so that the robot can move forwards.
However, due to my lack of experience with using servo motors (I'm more familiar with stepper motors), I had trouble with even this basic task and I could not for the life of me figure out why.
The two lines of code that I had trouble with was the following:

```
LeftWheel.write(180);
RightWheel.write(0);
```

I was informed that plugging in 0 would cause the servo to move at full speed in one direction while plugging in 180 would move it full speed in the other direction.
But no matter what number I plugged in or what modifications I made in the code, a problem would always appear:
- Only one servo would move.
- One servo would move significantly faster than the other.
- The two servos would move at the same speed but not in the same direction.
- The code would work perfectly one run and not work the next.

It took me a long time to realize my mistake *and how ridiculously stupid this error was*.

First, if you have two servos connected to the Arduino, they are **mirrored**.
Second, **Servo.write() is _only for 180-degree servos_ and for continous, 360-degree servos, _I have to use Servo.writeMicroseconds()_.**

On the bright side, I won't be forgetting that any time soon.

For now, the code is written so that you can change the speed and direction of both wheels by typing in a value in the Serial Monitor.
The next step would be to implement the code so that the vehicle can turn but I believe that won't be a problem now that I finally know how servos work.

For the first lab, we constructed a rather shabby first model and hastily put a breadboard circuit together.
With this first model, we managed to reach the first milestone by having the robot move forward.
However, our group met again later that week and we decided to clean up the design a bit.
A new body was created (thanks to Wenxuan) and the circuit on the breadboard was reworked (by me) so that it looked better.

By the end of week 2, we hope to have connected the camera to the Arduino and integrate that to the code so that the robot not only move towards a certain color but also avoid the white tape so that it doesn't move out of bounds.


### Entry by Shihan (Write about the progress with the camera)


## Division of Labor
**Steven Park**
- Set up the Arduino breadboard circuit
- Wrote the main Arduino code

**Wenxuan Guo**
- Constructed the body of the robot
- Researched the workings of the Pixy camera

**Shihan Zhao**
- Researched the workings of the Pixy camera and configured with its settings so that it can detect the various colors
