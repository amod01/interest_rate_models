// BDTModel.h

#ifndef BDT_MODEL_H
#define BDT_MODEL_H

#include "InterestRateModel.h"
#include <vector>

class BDTModel : public InterestRateModel {
private:
    double sigma0;   // Initial volatility
    double dt;

public:
    BDTModel(double sigma0_, double dt_);

    double simulateNextRate(double r, double dt, double z) const override;
    double bondPrice(double r, double T) const override;
};

#endif // BDT_MODEL_H
