#include <DistanceModel.h>

// Coefficients of the regressionFormula
static float w[3] = {
    28522.83962214,
    -11466.61167346,
    1152.38415113,
};

float DistanceModel::Linear::voltage2distance_cm(float voltage)
{
    return w[0] + w[1] * voltage + w[2] * voltage * voltage;
}
