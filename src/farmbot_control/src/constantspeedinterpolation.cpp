#include "constantspeedinterpolation.h"

#include "geometryhelper.h"

ConstantSpeedInterpolation::ConstantSpeedInterpolation()
{
  float initSpeed[3] = {0, 0, 0.01};
  float initEffort[3] = {0, 0, 0};
  GeometryHelper::fill3DArray(initSpeed, mSpeed);
  GeometryHelper::fill3DArray(initEffort, mEffort);
}

void ConstantSpeedInterpolation::oneStep()
{
  if (not finished()) {
    calculateNextPosition();
  }
}

bool ConstantSpeedInterpolation::finished()
{
  //mGoalReached == 0000 0111 ?
  return (mGoalReached == 0x07);
}

void ConstantSpeedInterpolation::calculateNextPosition() {
  float nextX = mCurrentX + mSpeed[0];
  if (nextX < mXGoal) {
    mCurrentX = nextX;
    //transform 0000 0XXX to 0000 0XX1
    mGoalReached = mGoalReached | 1;
  }

  float nextY = mCurrentY + mSpeed[1];
  if (nextX < mXGoal) {
    mCurrentY = nextY;
    //transform 0000 0XXX to 0000 0X1X
    mGoalReached = mGoalReached | (1 << 1);
  }

  float nextZ = mCurrentZ + mSpeed[2];
  if (nextX < mXGoal) {
    mCurrentZ = nextZ;
    //transform 0000 0XXX to 0000 01XX
    mGoalReached = mGoalReached | (1<<2);
  }
}

float* ConstantSpeedInterpolation::getNextPosition(float *nextPositionArray)
{
  nextPositionArray[0] = mCurrentX;
  nextPositionArray[1] = mCurrentY;
  nextPositionArray[2] = mCurrentZ;
  return nextPositionArray;
}

float* ConstantSpeedInterpolation::getNextSpeed(float* nextSpeedArray)
{
  GeometryHelper::fill3DArray(mSpeed, nextSpeedArray);
  return nextSpeedArray;
}

float* ConstantSpeedInterpolation::getNextEffort(float* nextEffortArray)
{
  GeometryHelper::fill3DArray(mEffort, nextEffortArray);
  return nextEffortArray;
}
