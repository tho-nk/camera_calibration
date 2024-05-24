#pragma once

#include <gmock/gmock.h>

#include "calibration/include/ICameraManager.hpp"

namespace bc = calibration;
namespace test {
class MockCameraManager : public bc::ICameraManager {
   public:
    MOCK_METHOD(bc::CameraParameters const&, getCameraParameters, (), (const override));
};

}  // namespace  test