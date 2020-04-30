#include "transitiongenesisstate.h"
#include "geometryhelper.h"

#include "ros/ros.h"

TransitionGenesisState::TransitionGenesisState()
{

}

void TransitionGenesisState::setNextPosition(float *position)
{
  GeometryHelper::fill3DArray(position, mNextPosition);
}

void TransitionGenesisState::setNextSpeed(float *speed)
{
  GeometryHelper::fill3DArray(speed, mNextSpeed);
}

void TransitionGenesisState::setNextEffort(float *effort)
{
  GeometryHelper::fill3DArray(effort, mNextEffort);
}

sensor_msgs::JointState TransitionGenesisState::createJointStateFromData()
{
  mJointStateAfterTransition.header.stamp = ros::Time::now();
  mJointStateAfterTransition.name.push_back("joint_cross_slide_z_axis");
  mJointStateAfterTransition.effort.push_back(mNextEffort[2]);
  mJointStateAfterTransition.position.push_back(mNextPosition[2]);
  mJointStateAfterTransition.velocity.push_back(mNextSpeed[2]);
  return mJointStateAfterTransition;
}
