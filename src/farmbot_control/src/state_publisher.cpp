#include <iostream>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<sensor_msgs::JointState>("/farmbot/joint_states", 1000);
  int iteration = 0;

  ros::Rate loop_rate(2);
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    sensor_msgs::JointState jointStates;
    jointStates.header.stamp = ros::Time::now();
    std::string name[1];
    jointStates.name.push_back("joint_cross_slide_z_axis");
    jointStates.effort.push_back(0);
    jointStates.position.push_back(iteration*0.01);
    jointStates.velocity.push_back(0.01*2);


    chatter_pub.publish(jointStates);

    ros::spinOnce();

    loop_rate.sleep();
    iteration++;
  }

  return 0;
}
