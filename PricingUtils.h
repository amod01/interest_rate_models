// PricingUtils.h

#ifndef PRICING_UTILS_H
#define PRICING_UTILS_H

#include <vector>

namespace PricingUtils {
    double average(const std::vector<double>& values);
    double discountFactor(double r, double T);
    double forwardRate(double spot, double T, double maturity);
}

#endif // PRICING_UTILS_H
