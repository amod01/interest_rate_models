// VasicekModel.cpp

#include "VasicekModel.h"

VasicekModel::VasicekModel(double kappa_, double theta_, double sigma_)
    : kappa(kappa_), theta(theta_), sigma(sigma_) {}

double VasicekModel::simulateNextRate(double r, double dt, double random) const {
    return r + kappa * (theta - r) * dt + sigma * std::sqrt(dt) * random;
}

double VasicekModel::bondPrice(double r0, double T) const {
    return std::exp(-r0 * T); // Simplified Vasicek bond price formula
}
