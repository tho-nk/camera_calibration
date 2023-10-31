#include "Calibration.hpp"

#include <iostream>

namespace bilberry::calibration {
Calibration::Calibration(/* args */) {}

Calibration::~Calibration() {}

void Calibration::run() { std::cout << "hello from Calibration" << std::endl; }
}  // namespace bilberry::calibration