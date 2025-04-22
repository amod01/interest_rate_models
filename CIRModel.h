// CIRModel.h

#ifndef CIR_MODEL_H
#define CIR_MODEL_H

#include "InterestRateModel.h"
#include <cmath>

class CIRModel : public InterestRateModel {
public:
    CIRModel(double kappa, double theta, double sigma);

    double simulateNextRate(double r, double dt, double random) const override;
    double bondPrice(double r0, double T) const override;

private:
    double kappa;  // Speed of mean reversion
    double theta;  // Long-term mean
    double sigma;  // Volatility
};

#endif // CIR_MODEL_H
