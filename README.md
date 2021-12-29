# Robot control arm
## Description
In this project, my partner Lucas Trubiano and I implemented a Graphical Interface and Client-Server Connection for the control of an ABB IRB 460 robotic arm. We also used the robotics toolbox from Peter Corke's library with which we were able to simulate the robot and visualize how the robot did the customer's instructions.

## Goals
- Implement OOP.
- Use layer models (at least 2), so that the solution
You can use it regardless of whether there is a graphical or console interface.
- Server-side modules must be developed in Python
- The client-side modules must be developed in C ++.
- The development must be operational under the Linux platform for the modules on the side
server and client.
### Server-side services:
- Robot control panel, through console (CLI) that allows to perform:
  - Connection / disconnection to the Robot using serial communication.
  - Activation / Deactivation of the robot.
  - List of control commands
  - Help with exemplification of the required syntax3 for the commands that require it.
- XML-RPC server, capable of executing the same operations previously requested remotely.
- The console application must implement inheritance from the Cmd class

### Client side services. The main interface should offer:
  - Robot control panel, with functionalities similar to those of the console interface.
  - Report showing the connection, the Robot's activity status, the time (accumulated) from the start of the activity, the starting time of each order, the coordinates of each robot joint and, if available, the speed of the end effector.
  - GUI of control and monitoring of parameters.
  - Visual display of the robot, using 3D view or projections.
  - Table or curves showing the speed of each of the links.
  - Learning the trajectory with storage of the corresponding orders in a text file (readable) that allows it to be reproduced.
