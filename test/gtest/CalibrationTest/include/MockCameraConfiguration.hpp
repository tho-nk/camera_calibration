#pragma once

#include <gmock/gmock.h>

#include "calibration/include/ICameraConfiguration.hpp"

namespace bc = bilberry::calibration;
namespace bilberry::test {
class MockCameraConfiguration : public bc::ICameraConfiguration {
   public:
    MOCK_METHOD(bc::CameraParameters, loadCamera, (const std::string& filePath), (override));
};

}  // namespace bilberry::test