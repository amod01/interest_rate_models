// VasicekModel.h

#ifndef VASICEK_MODEL_H
#define VASICEK_MODEL_H

#include "InterestRateModel.h"
#include <cmath>

class VasicekModel : public InterestRateModel {
public:
    VasicekModel(double kappa, double theta, double sigma);

    double simulateNextRate(double r, double dt, double random) const override;
    double bondPrice(double r0, double T) const override;

private:
    double kappa;  // Speed of mean reversion
    double theta;  // Long-term mean
    double sigma;  // Volatility
};

#endif // VASICEK_MODEL_H
