#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "MockCameraConfiguration.hpp"
#include "MockImageManager.hpp"
#include "calibration/include/Calibration.hpp"

namespace bc = bilberry::calibration;

namespace bilberry::test {

class CalibrationBilberryTest : public ::testing::Test {
   protected:
    CalibrationBilberryTest()
        : mockImageManager(std::make_shared<MockImageManager>()),
          mockCameraConfiguration(std::make_shared<MockCameraConfiguration>()),
          calib(mockImageManager, mockCameraConfiguration)
    {
    }

    void SetUp() override {}

    std::shared_ptr<MockImageManager> mockImageManager;
    std::shared_ptr<MockCameraConfiguration> mockCameraConfiguration;

    bc::Calibration calib;
};

TEST_F(CalibrationBilberryTest, DrawLineTest)
{
    const std::filesystem::path inputPath("/workspaces/bilberry/calibration.jpg");
    const std::filesystem::path outputPath("/workspaces/bilberry/calibration_.jpg");
    auto image = cv::imread(inputPath);

    cv::Point start(738, 645);
    cv::Point end(1665, 621);
    cv::Scalar color(0, 0, 255);
    std::shared_ptr<bc::ImageManager> realImageManager = std::make_shared<bc::ImageManager>();

    EXPECT_CALL(*mockImageManager, load(inputPath)).Times(1).WillOnce(testing::Return(image));
    auto loadedImage = calib.load(inputPath);
    calib.drawLine(loadedImage, start, end, color, 2);
    EXPECT_CALL(*mockImageManager, save(outputPath, testing::Ref(loadedImage))).Times(1);
    calib.save(outputPath, loadedImage);

    // cv::imwrite(outputPath.string(), loadedImage);

    EXPECT_EQ(200, 20);
}

}  // namespace bilberry::test