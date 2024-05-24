#pragma once

#include "ICameraManager.hpp"

namespace calibration {
class CameraManager : public ICameraManager {
   public:
    CameraManager(const std::filesystem::path& configPath);
    virtual ~CameraManager() = default;

    virtual CameraParameters const& getCameraParameters() const override;

   private:
    void load_();

    std::filesystem::path configPath_;
    CameraParameters cameraParameters_;
};
}  // namespace  calibration