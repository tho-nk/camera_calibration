#pragma once

#include <string>

#include "CameraParameters.hpp"

namespace bilberry::calibration {
class ICameraConfiguration {
   public:
    ICameraConfiguration() = default;
    virtual ~ICameraConfiguration() = default;

    virtual CameraParameters loadCamera(const std::string& filePath) = 0;
};
}  // namespace bilberry::calibration