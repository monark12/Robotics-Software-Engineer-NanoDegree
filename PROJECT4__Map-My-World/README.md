[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)


<h2>Project 4 --> Map My World</h2>

![localization](localization.gif)

<h3>Project Overview and Requiments</h3>
The project flow will be as follows:

 * You will develop your own package to interface with the rtabmap_ros package.
 * You will build upon your localization project to make the necessary changes to interface the robot with RTAB-Map. An example of this is the addition of an RGB-D camera.
 * You will ensure that all files are in the appropriate places, all links are properly connected, naming is properly setup and topics are correctly mapped. Furthermore you will need to generate the appropriate launch files to launch the robot and map its surrounding environment.
 * When your robot is launched you will teleop around the room to generate a proper map of the environment.

### Dependencies
* Gazebo >= 7.0  
* ROS Kinetic  
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

### Project Description  
Directory Structure  
```
PROJECT4__Map-My-World
├── README.md
└── src
    ├── CMakeLists.txt -> /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
    ├── amcl (...)
    ├── ball_chaser
    │   ├── CMakeLists.txt
    │   ├── launch
    │   │   └── ball_chaser.launch
    │   ├── package.xml
    │   ├── src
    │   │   ├── drive_bot.cpp
    │   │   └── process_image.cpp
    │   └── srv
    │       └── DriveToTarget.srv
    ├── my_robot
    │   ├── CMakeLists.txt
    │   ├── config
    │   │   ├── base_local_planner_params.yaml
    │   │   ├── costmap_common_params.yaml
    │   │   ├── global_costmap_params.yaml
    │   │   └── local_costmap_params.yaml
    │   ├── launch
    │   │   ├── amcl.launch
    │   │   ├── localization.launch
    │   │   ├── mapping.launch
    │   │   ├── robot_description.launch
    │   │   ├── teleop.launch
    │   │   └── world.launch
    │   ├── maps
    │   │   ├── map.pgm
    │   │   └── map.yaml
    │   ├── mesh
    │   │   └── hokuyo.dae
    │   ├── package.xml
    │   ├── urdf
    │   │   ├── my_robot.gazebo
    │   │   └── my_robot.xacro
    │   └── worlds
    │       ├── empty.world
    │       ├── monark.world
    │       └── monark_old.world
    ├── rtabmap_ros (...)
    └── teleop_twist_keyboard (...)

```
Most of the files are already explained in the previous projects. For this projects, the main changes are the 
 - [rtabmap_ros](https://github.com/introlab/rtabmap_ros): This package is a ROS wrapper of a RGB-D SLAM approach based on a global loop closure detector with real-time constraints. This package can be used to generate a 3D point clouds of the environment and/or to create a 2D occupancy grid map for navigation. 
 - [my_robot](/src/my_robot): This package contains our world and robot model, and launch files meant for specific purposes
   - [config](/src/my_robot/config/): Map file generated from pgm_map_creator.
   - [amcl.launch](/src/my_robot/launch/amcl.launch): Launches 2 nodes
     - amcl node which takes `odometry` and `laser scan data` to perform the AMCL localization.
     - move_base node from [move_base](http://wiki.ros.org/move_base) package. It provides implementation for navigation given a nav_goal path.

### Run the project  
* Clone this repository  
```bash
cd PROJECT3__Where-Am-I/src
catkin_init_workspace # To create a symlink from /opt/ros/kinetic/share/catkin/cmake/toplevel.cmake
```

* add `add_compile_options(-std=c++11)` in PROJECT3__Where-Am-I/src/CMakeLists.txt
```
cd PROJECT3__Where-Am-I/
catkin_make
```

* Launch the robot inside your world 
```bash
cd PROJECT2__Go-Chase-It/
source devel/setup.bash
roslaunch my_robot world.launch # this will also launch rviz visualizer
```

* Launch amcl and move_base using the amcl.launch file.
* Open a new terminal.
```bash
cd PROJECT2__Go-Chase-It/
source devel/setup.bash
roslaunch my_robot amcl.launch
```