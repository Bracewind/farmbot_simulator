#ifndef TRANSITIONGENESISSTATE_H
#define TRANSITIONGENESISSTATE_H

#include "sensor_msgs/JointState.h"

class TransitionGenesisState
{
private:
  float mNextPosition[3];
  float mNextSpeed[3];
  float mNextEffort[3];

  sensor_msgs::JointState mJointStateAfterTransition;

public:
  TransitionGenesisState();

  void setNextPosition(float position[3]);
  void setNextSpeed(float speed[3]);
  void setNextEffort(float effort[3]);

  sensor_msgs::JointState createJointStateFromData();
};

#endif // TRANSITIONGENESISSTATE_H
