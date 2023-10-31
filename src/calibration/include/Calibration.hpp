#pragma once

#include <filesystem>

#include "CameraParameters.hpp"

namespace bilberry::calibration {
class Calibration {
   public:
    Calibration(/* args */);
    ~Calibration();
    void run();

   private:
    CameraParameters cameraParameters;
    // hardcoding for now
    std::filesystem::path filePath = "/workspaces/bilberry/calibration.jpg";
};

}  // namespace bilberry::calibration