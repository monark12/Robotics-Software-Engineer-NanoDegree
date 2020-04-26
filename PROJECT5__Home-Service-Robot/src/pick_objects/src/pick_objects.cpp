#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <visualization_msgs/Marker.h>
#include <iostream>

bool pickup_goal_received=false;
bool dropoff_goal_received=false;

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

void marker_callback(const visualization_msgs::Marker::ConstPtr& msg){
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose = msg->pose;

  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);
  ac.waitForResult();

  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("robot reached the goal location");
  	sleep(5);
  }
  else
    ROS_INFO("The base failed to move");
  
}

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");
  ros::NodeHandle n;
  ros::Subscriber marker_sub = n.subscribe("visualization_marker", 1, marker_callback);
  //tell the action client that we want to spin a thread by default

  while(ros::ok()){
  	ros::spinOnce();
  }  
  
}