#include "Simulator.h"
#include <random>
#include <vector>

// Simulates bond price by running paths with Monte Carlo simulation
double simulateBondPrice(const InterestRateModel& model, double r0, double T, int numPaths, std::vector<double>& paths) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 1.0);
    double dt = T / 100.0;  // Time step (assuming 100 steps in total)

    // Run multiple paths to calculate the average bond price
    double bondPriceSum = 0.0;

    for (int i = 0; i < numPaths; ++i) {
        double r = r0; // Initialize interest rate
        for (int j = 0; j < 100; ++j) {  // Simulate 100 time steps
            double z = distribution(generator); // Random shock (from normal distribution)
            r = model.simulateNextRate(r, dt, z); // Simulate the next rate
        }

        // Calculate the bond price at time T using the final rate `r`
        double bondPrice = model.bondPrice(r, T);
        bondPriceSum += bondPrice;

        paths.push_back(bondPrice); // Store the bond price for the current path
    }

    // Return the average bond price from all the paths
    return bondPriceSum / numPaths;
}
