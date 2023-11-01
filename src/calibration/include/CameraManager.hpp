#pragma once

#include "ICameraManager.hpp"

namespace bilberry::calibration {
class CameraManager : public ICameraManager {
   public:
    CameraManager() = default;
    virtual ~CameraManager() = default;

    virtual CameraParameters load(const std::filesystem::path& configPath) override;
};
}  // namespace bilberry::calibration