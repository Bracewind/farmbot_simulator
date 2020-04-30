#include "geometryhelper.h"

namespace GeometryHelper {
  void fill3DArray(float* arrayToCopy, float*arrayReceivingCopy)
  {
    arrayReceivingCopy[0] = arrayToCopy[0];
    arrayReceivingCopy[1] = arrayToCopy[1];
    arrayReceivingCopy[2] = arrayToCopy[2];
  }
}
