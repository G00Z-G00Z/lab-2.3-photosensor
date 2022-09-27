#include <DistanceModel.h>

// Coefficients of the regressionFormula
static float w[2] = {
    1, // w0
    1  // w1
};

float DistanceModel::Linear::voltage2distance_cm(float voltage)
{
    return w[0] + w[1] * voltage;
}
