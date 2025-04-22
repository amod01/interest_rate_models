// InterestRateModel.h

#ifndef INTEREST_RATE_MODEL_H
#define INTEREST_RATE_MODEL_H

#include <functional>

class InterestRateModel {
public:
    virtual ~InterestRateModel() = default;
    virtual double simulateNextRate(double r, double dt, double random) const = 0;
    virtual double bondPrice(double r0, double T) const = 0;
};

#endif // INTEREST_RATE_MODEL_H
