#ifndef CONSTANTSPEEDINTERPOLATION_H
#define CONSTANTSPEEDINTERPOLATION_H

/**
 * \class ConstantSpeedInterpolation constantspeedinterpolation.h
 * \brief Generate next parameters for a constant speed
 *
 * The ConstantSpeedInterpolation class is used to generate next position
 * speed and effort for simulation when the speed is constant.
 * The speed given is the vector speed for the whole farmbot, meaning that it is not
 * relative to one joint.
 * The ConstantSpeedInterpolation class is used to generate the path of value that the robot will
 * be taking, and does not specify how to go from one state to another.
 * The class TransitionState is the one responsible for that last job.
 * \see TransitionState
 */
class ConstantSpeedInterpolation
{
private:
  float mCurrentX, mCurrentY, mCurrentZ;
  float mXGoal, mYGoal, mZGoal;
  float mSpeed[3];
  float mEffort[3];
  unsigned char mGoalReached = 0x00;

  void calculateNextPosition();

public:
  ConstantSpeedInterpolation();

  void oneStep();
  bool finished();

  float* getNextPosition(float* nextPositionArray);
  float* getNextSpeed(float* nextSpeedArray);
  float* getNextEffort(float* nextEffortArray);

};

#endif // CONSTANTSPEEDINTERPOLATION_H
