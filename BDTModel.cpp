// BDTModel.cpp

#include "BDTModel.h"
#include <cmath>

BDTModel::BDTModel(double sigma0_, double dt_)
    : sigma0(sigma0_), dt(dt_) {}

double BDTModel::simulateNextRate(double r, double dt, double z) const {
    // Assume lognormal short rate: r(t+dt) = r * exp((mu - 0.5*sigma^2)*dt + sigma*sqrt(dt)*z)
    double sigma = sigma0; // constant for now
    return r * std::exp(-0.5 * sigma * sigma * dt + sigma * std::sqrt(dt) * z);
}

double BDTModel::bondPrice(double r, double T) const {
    // Approximation: use exp(-r * T)
    return std::exp(-r * T);
}
