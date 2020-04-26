[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

<h2>Project 5 --> Home Service Robot</h2>

<!-- ![home_service_robot](home_service_robot.gif) -->
<video src="home-service-robot.mov" width="320" height="200" controls preload></video>


* To generate map.pgm file from .db file generated using SLAM project.
```
roscore
rosrun rtabmap_ros rtabmap _database_path:=~/Downloads/bigmap.db
rosrun map_server map_saver map:=proj_map
rosservice call /publish_map 1 1 0
```