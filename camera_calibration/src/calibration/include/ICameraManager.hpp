#pragma once

#include <rapidjson/document.h>

#include <filesystem>
#include <string>

#include "CameraParameters.hpp"

namespace calibration {
class ICameraManager {
   public:
    ICameraManager() = default;
    virtual ~ICameraManager() = default;

    virtual CameraParameters const& getCameraParameters() const = 0;
};
}  // namespace  calibration