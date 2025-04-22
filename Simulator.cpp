// Simulator.cpp

#include "Simulator.h"
#include <iostream>
#include <vector>
#include <random>

std::vector<double> Simulator::simulateRates(const InterestRateModel& model, double r0, double dt, int steps, int paths) {
    std::default_random_engine gen;
    std::normal_distribution<double> dist(0.0, 1.0);
    std::vector<double> rates(paths);

    for (int i = 0; i < paths; ++i) {
        double r = r0;
        for (int j = 0; j < steps; ++j) {
            r = model.simulateNextRate(r, dt, dist(gen));
        }
        rates[i] = r; // Store the final rate of this path
    }
    return rates;
}

double Simulator::simulateBondPrice(const InterestRateModel& model, double r0, double T, int paths) {
    double totalPrice = 0.0;
    std::vector<double> rates = simulateRates(model, r0, 0.01, 100, paths);

    for (double r : rates) {
        totalPrice += model.bondPrice(r, T);
    }

    return totalPrice / paths; // Average bond price
}
