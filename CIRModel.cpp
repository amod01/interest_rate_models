// CIRModel.cpp

#include "CIRModel.h"

CIRModel::CIRModel(double kappa_, double theta_, double sigma_)
    : kappa(kappa_), theta(theta_), sigma(sigma_) {}

double CIRModel::simulateNextRate(double r, double dt, double random) const {
    return r + kappa * (theta - r) * dt + sigma * std::sqrt(r * dt) * random;
}

double CIRModel::bondPrice(double r0, double T) const {
    return std::exp(-r0 * T); // Simplified CIR bond price formula
}
