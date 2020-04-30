#include <iostream>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"

#include "transitiongenesisstate.h"
#include "constantspeedinterpolation.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<sensor_msgs::JointState>("/farmbot/joint_states", 1000);


  ros::Rate loop_rate(50);
  float z = 0;

  ConstantSpeedInterpolation pathFinder;
  TransitionGenesisState transitionState;

  while (z >= -0.2 && ros::ok())
  {

    float velocity = 0.001;

    int iteration = 0;

    while (!pathFinder.finished()) {

      sensor_msgs::JointState jointStates;

      //calculate the next state for doing the animation
      pathFinder.oneStep();

      //find the jointState associated to the state found
      float position[3];
      float velocity[3];
      float effort[3];

      transitionState.setNextPosition(pathFinder.getNextPosition(position));
      transitionState.setNextSpeed(pathFinder.getNextSpeed(velocity));
      transitionState.setNextEffort(pathFinder.getNextEffort(effort));
      jointStates = transitionState.createJointStateFromData();

      chatter_pub.publish(jointStates);

      ros::spinOnce();

      loop_rate.sleep();
      iteration++;
    }


    std::string key;
    std::cin >> key;
    z = stof(key);
  }

  return 0;
}
