// HullWhiteModel.cpp

#include "HullWhiteModel.h"
#include <cmath>

HullWhiteModel::HullWhiteModel(double a_, double sigma_)
    : a(a_), sigma(sigma_) {}

double HullWhiteModel::simulateNextRate(double r, double dt, double z) const {
    return r + a * (0.05 - r) * dt + sigma * std::sqrt(dt) * z; // using 0.05 as mock forward rate
}

double HullWhiteModel::bondPrice(double r, double T) const {
    double B = (1.0 - std::exp(-a * T)) / a;
    double A = std::exp((B - T) * (0.05 * a - 0.5 * sigma * sigma / (a * a)) - 
                        (sigma * sigma * B * B) / (4 * a));
    return A * std::exp(-B * r);
}
