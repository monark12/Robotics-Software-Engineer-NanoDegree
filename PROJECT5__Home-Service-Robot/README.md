[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

<h2>Project 5 --> Home Service Robot</h2>

<iframe width="560" height="315" src="https://www.youtube.com/embed/HQ9H_l-Sfo4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

* To generate map.pgm file from .db file generated using SLAM project.
```
roscore
rosrun rtabmap_ros rtabmap _database_path:=~/Downloads/bigmap.db
rosrun map_server map_saver map:=proj_map
rosservice call /publish_map 1 1 0
```