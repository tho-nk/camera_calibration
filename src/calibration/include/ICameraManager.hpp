#pragma once

#include <rapidjson/document.h>

#include <filesystem>
#include <string>

#include "CameraParameters.hpp"

namespace bilberry::calibration {
class ICameraManager {
   public:
    ICameraManager() = default;
    virtual ~ICameraManager() = default;

    virtual CameraParameters load(const std::filesystem::path& configPath) = 0;
};
}  // namespace bilberry::calibration