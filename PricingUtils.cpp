// PricingUtils.cpp

#include "PricingUtils.h"
#include <cmath>

namespace PricingUtils {

    double average(const std::vector<double>& values) {
        double sum = 0.0;
        for (double value : values) {
            sum += value;
        }
        return sum / values.size();
    }

    double discountFactor(double r, double T) {
        return std::exp(-r * T); // Basic discount factor
    }

    double forwardRate(double spot, double T, double maturity) {
        return (spot * maturity) / T;
    }

}
