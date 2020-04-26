#!/bin/sh
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/map/map.yaml
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/map/monark.world
export RVIZ_CONFIG_FILE=/home/workspace/catkin_ws/src/rvizConfig/myconfig.rviz

xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch " & 
sleep 10
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " & 
sleep 5
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" & 
sleep 5
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; rosrun add_markers add_markers" & 
sleep 5
