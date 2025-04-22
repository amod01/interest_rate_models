// HullWhiteModel.h

#ifndef HULL_WHITE_MODEL_H
#define HULL_WHITE_MODEL_H

#include "InterestRateModel.h"

class HullWhiteModel : public InterestRateModel {
private:
    double a;       // Mean reversion speed
    double sigma;   // Volatility

public:
    HullWhiteModel(double a_, double sigma_);
    
    double simulateNextRate(double r, double dt, double randomShock) const override;
    double bondPrice(double r, double T) const override;
};

#endif // HULL_WHITE_MODEL_H
