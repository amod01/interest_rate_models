// HJMModel.h

#ifndef HJM_MODEL_H
#define HJM_MODEL_H

#include "InterestRateModel.h"
#include <vector>
#include <functional>

class HJMModel : public InterestRateModel {
private:
    double sigma;
    std::function<double(double)> forwardCurve;

public:
    HJMModel(double sigma_, std::function<double(double)> fwdCurve);

    double simulateNextRate(double r, double dt, double z) const override;
    double bondPrice(double r, double T) const override;
};

#endif // HJM_MODEL_H
