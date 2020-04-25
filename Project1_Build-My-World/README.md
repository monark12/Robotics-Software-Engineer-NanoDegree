<h2>Project 1 --> Build My Robot</h2>

![my_world](Project1_Build-My-World/my_world.png)

<h3>Project Overview and Requiments</h3>

In this project I had to create a simulation world in **Gazebo** for all of my upcoming projects in the Udacity Robotics Software Engineer Nanodegree Program.

 1. Build a single floor wall structure using the **Building Editor** tool in Gazebo. Apply at least one feature, one color, and optionally one texture to your structure. Make sure there's enough space between the walls for a robot to navigate.
 2. Model any object of your choice using the **Model Editor** tool in Gazebo. Your model links should be connected with **joints**.
 3. Import your structure and two instances of your model inside an empty Gazebo World.
 4. Import at least one model from the **Gazebo online library** and implement it in your existing Gazebo world.
 5. Write a **C++ World Plugin** to interact with your world. Your code should display “Welcome to ’s World!” message as soon as you launch the Gazebo world file.

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
Project1_Build-My-World               # Build My World Project 
├── model                             # Model files
│   ├── 4wheelrobot
│   │   ├── model.config              
│   │   └── model.sdf
│   └── projectbuilding
│       ├── model.config
│       └── model.sdf
├── script                            # Gazebo World plugin C++ script
│   └── hello.cpp
└── world                             # Gazebo main World containing models 
    └── project_world
├── CMakeLists.txt                    # Link libraries 
```
- [project_world](/world/project_world): Gazebo world file that includes the models.  
- [projectbuilding](/model/projectbuilding): A single floor structure designed in the Building Editor tool of Gazebo.
- [4wheelrobot](/model/4wheelrobot): A robot designed in the Model Editor tool of Gazebo.  
- [hello.cpp](/script/hello.cpp): Gazebo world plugin C++ script.  
- [CMakeLists.txt](CMakeLists.txt): File to link the C++ code to libraries.  

### Run the project  
* Clone this repository
* At the top level of the project repository, create a build directory:  
```bash
cd Project1_Build-My-World/
mkdir build && cd build
```
* In `/build` directory, compile your code with  
```bash
cmake .. && make
```
* Export your plugin folder in the terminal so your world file can find it:  
```bash
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/home/workspace/Project1_Build-My-World/build
```
* Launch the world file in Gazebo to load both the world and plugin  
```bash
cd /home/workspace/github/Project1_Build-My-World/world/
gazebo project_world