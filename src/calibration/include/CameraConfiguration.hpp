#pragma once

#include "ICameraConfiguration.hpp"

namespace bilberry::calibration {
class CameraConfiguration : public ICameraConfiguration {
   public:
    CameraConfiguration() = default;
    virtual ~CameraConfiguration() = default;

    virtual CameraParameters loadCamera(const std::string& filePath) override;
};
}  // namespace bilberry::calibration