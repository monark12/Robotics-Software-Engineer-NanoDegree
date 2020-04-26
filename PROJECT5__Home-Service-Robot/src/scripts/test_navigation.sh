#!/bin/sh
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/map/map.yaml
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/map/monark.world

xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch " & 
sleep 10
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch " & 
sleep 5
xterm  -e  " source /home/workspace/catkin_ws/devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" & 
sleep 5