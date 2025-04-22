#include "VasicekModel.h"
#include "CIRModel.h"
#include "HullWhiteModel.h"
#include "BDTModel.h"
#include "HJMModel.h"
#include "HoLeeModel.h"
#include "Simulator.h"
#include "PricingUtils.h"
#include <iostream>
#include <vector>

int main() {
    // Initialize parameters
    double r0 = 0.03;  // Initial interest rate
    double T = 1.0;     // Time to maturity (1 year)
    int numPaths = 1000; // Number of paths to simulate

    // Initialize models
    VasicekModel vasicek(0.1, 0.05, 0.01);
    CIRModel cir(0.1, 0.05, 0.01);
    HullWhiteModel hullWhite(0.1, 0.01);
    BDTModel bdt(0.02, 0.01);
    HoLeeModel hoLee(0.01, [](double t) { return 0.02; });

    // Dummy forward curve for HJM
    auto forwardCurve = [](double t) { return 0.03 + 0.002 * t; };
    HJMModel hjm(0.01, forwardCurve);

    // Vector to store bond prices for each model
    std::vector<double> vasicekPaths, cirPaths, hullWhitePaths, bdtPaths, hjmPaths, hoLeePaths;

    // Simulate bond prices for each model
    double vasicekBondPrice = simulateBondPrice(vasicek, r0, T, numPaths, vasicekPaths);
    double cirBondPrice = simulateBondPrice(cir, r0, T, numPaths, cirPaths);
    double hullWhiteBondPrice = simulateBondPrice(hullWhite, r0, T, numPaths, hullWhitePaths);
    double bdtBondPrice = simulateBondPrice(bdt, r0, T, numPaths, bdtPaths);
    double hjmBondPrice = simulateBondPrice(hjm, r0, T, numPaths, hjmPaths);
    double hoLeeBondPrice = simulateBondPrice(hoLee, r0, T, numPaths, hoLeePaths);

    // Output the average bond prices for each model
    std::cout << "Average Bond Price for Vasicek Model: " << vasicekBondPrice << std::endl;
    std::cout << "Average Bond Price for CIR Model: " << cirBondPrice << std::endl;
    std::cout << "Average Bond Price for Hull-White Model: " << hullWhiteBondPrice << std::endl;
    std::cout << "Average Bond Price for BDT Model: " << bdtBondPrice << std::endl;
    std::cout << "Average Bond Price for HJM Model: " << hjmBondPrice << std::endl;
    std::cout << "Average Bond Price for Ho-Lee Model: " << hoLeeBondPrice << std::endl;

    return 0;
}
