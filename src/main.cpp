#include <iostream>

#include "calibration/include/Calibration.hpp"

int main() {
    std::cout << "Hello from bilberry" << std::endl;
    bilberry::calibration::Calibration aCal;
    aCal.run();
    return 0;
}