// HJMModel.cpp

#include "HJMModel.h"
#include <cmath>

HJMModel::HJMModel(double sigma_, std::function<double(double)> fwdCurve)
    : sigma(sigma_), forwardCurve(fwdCurve) {}

double HJMModel::simulateNextRate(double r, double dt, double z) const {
    // Very simplified HJM with constant volatility and deterministic forward curve
    return r + sigma * std::sqrt(dt) * z;
}

double HJMModel::bondPrice(double r, double T) const {
    // Approximate zero-coupon bond price using forward rate
    double f0 = forwardCurve(T);
    return std::exp(-f0 * T);
}
