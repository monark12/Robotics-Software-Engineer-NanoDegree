#include "ros/ros.h"
#include <geometry_msgs/Twist.h>

//TODO: Include the ball_chaser "DriveToTarget" header file
#include "ball_chaser/DriveToTarget.h"

// Global joint publisher objects
ros::Publisher motor_command_publisher;

// This callback function executes whenever a drive to target service is requested
bool handle_robot_drive_request(ball_chaser::DriveToTarget::Request& req,
    ball_chaser::DriveToTarget::Response& res)
{

    ROS_INFO("DriveToTarget received - j1:%1.2f, j2:%1.2f", (float)req.linear_x, (float)req.angular_z);
    // Create a motor_command object of type geometry_msgs::Twist
    geometry_msgs::Twist motor_command;
    motor_command.linear.x = (float)req.linear_x;
    motor_command.angular.z = (float)req.angular_z;
    
  // Publish angles to drive the robot
    motor_command_publisher.publish(motor_command);
    
  	return true;
}

int main(int argc, char** argv)
{
    // Initialize the arm_mover node and create a handle to it
    ros::init(argc, argv, "drive_bot");
    ros::NodeHandle n;

    // Define one publishers to publish geometry_msgs::Twist messages on joint respective topics
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    // TODO: Define a drive /ball_chaser/command_robot service with a handle_drive_request callback function
    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_robot_drive_request);

  	
    // Handle ROS communication events
    ros::spin();

    return 0;
}
