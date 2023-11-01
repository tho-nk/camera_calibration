#pragma once

#include <gmock/gmock.h>

#include "calibration/include/ICameraManager.hpp"

namespace bc = bilberry::calibration;
namespace bilberry::test {
class MockCameraManager : public bc::ICameraManager {
   public:
    MOCK_METHOD(bc::CameraParameters, load, (const std::filesystem::path& configPath), (override));
};

}  // namespace bilberry::test