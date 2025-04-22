// HoLeeModel.cpp

#include "HoLeeModel.h"
#include <cmath>

HoLeeModel::HoLeeModel(double sigma_, std::function<double(double)> thetaFunc)
    : sigma(sigma_), theta(thetaFunc) {}

double HoLeeModel::simulateNextRate(double r, double dt, double z) const {
    // Simple Euler discretization: r(t+dt) = r + theta(t) * dt + sigma * sqrt(dt) * z
    double t = 0; // assuming time starts at 0 — could be passed in for more generality
    return r + theta(t) * dt + sigma * std::sqrt(dt) * z;
}

double HoLeeModel::bondPrice(double r, double T) const {
    // Approximate zero-coupon bond price using flat term structure
    return std::exp(-r * T);
}
