#pragma once

#include <gmock/gmock.h>

#include "calibration/include/IImageManager.hpp"

namespace bc = calibration;
namespace test {
class MockImageManager : public bc::IImageManager {
   public:
    MOCK_METHOD(cv::Mat, load, (const std::filesystem::path&), (const override));
    MOCK_METHOD(void, save, (const std::filesystem::path&, const cv::Mat& cvMat), (const override));
};

}  // namespace  test