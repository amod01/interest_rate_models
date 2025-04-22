// Simulator.h

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "InterestRateModel.h"
#include <vector>
#include <random>

class Simulator {
public:
    static std::vector<double> simulateRates(const InterestRateModel& model, double r0, double dt, int steps, int paths);
    static double simulateBondPrice(const InterestRateModel& model, double r0, double T, int paths);
};

// Function to simulate bond prices using Monte Carlo simulation
double simulateBondPrice(const InterestRateModel& model, double r0, double T, int numPaths, std::vector<double>& paths);


#endif // SIMULATOR_H
