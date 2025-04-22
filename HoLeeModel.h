// HoLeeModel.h

#ifndef HOLEE_MODEL_H
#define HOLEE_MODEL_H

#include "InterestRateModel.h"
#include <functional>

class HoLeeModel : public InterestRateModel {
private:
    double sigma;
    std::function<double(double)> theta; // time-dependent drift term

public:
    HoLeeModel(double sigma_, std::function<double(double)> thetaFunc);

    double simulateNextRate(double r, double dt, double z) const override;
    double bondPrice(double r, double T) const override;
};

#endif // HOLEE_MODEL_H
