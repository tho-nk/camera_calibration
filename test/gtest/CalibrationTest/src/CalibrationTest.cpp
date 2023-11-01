#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "MockCameraConfiguration.hpp"
#include "MockImageManager.hpp"
#include "Utility.hpp"
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

TEST_F(CalibrationBilberryTest, drawLineTest)
{
    const std::filesystem::path inputPath("/workspaces/bilberry/base-line/input.jpg");
    const std::filesystem::path expectedPath("/workspaces/bilberry/base-line/expectedLine.png");

    cv::Point start(738, 645);
    cv::Point end(1665, 621);
    cv::Scalar color(0, 0, 255);
    auto originalImage = cv::imread(inputPath);

    auto receivedImage = originalImage.clone();
    calib.drawLine(receivedImage, start, end, color, 5);

    auto expectedImage = cv::imread(expectedPath.string());

    ASSERT_FALSE(expectedImage.empty());
    ASSERT_FALSE(receivedImage.empty());
    ASSERT_EQ(expectedImage.cols, receivedImage.cols);
    ASSERT_EQ(expectedImage.rows, receivedImage.rows);
    ASSERT_TRUE(expectedImage.type() == receivedImage.type());

    auto areIdentical = compareImage(expectedImage, receivedImage);
    EXPECT_TRUE(areIdentical);
}

TEST_F(CalibrationBilberryTest, drawRectangleTest)
{
    const std::filesystem::path inputPath("/workspaces/bilberry/base-line/input.jpg");
    const std::filesystem::path expectedPath("/workspaces/bilberry/base-line/expectedRectangle.png");

    cv::Point p1(738, 645);
    cv::Point p2(1665, 621);
    cv::Point p3(1754, 1066);
    cv::Point p4(678, 1088);
    cv::Scalar color(0, 0, 255);
    auto originalImage = cv::imread(inputPath);

    auto receivedImage = originalImage.clone();
    calib.drawLine(receivedImage, p1, p2, color, 5);
    calib.drawLine(receivedImage, p2, p3, color, 5);
    calib.drawLine(receivedImage, p3, p4, color, 5);
    calib.drawLine(receivedImage, p4, p1, color, 5);

    auto expectedImage = cv::imread(expectedPath.string());

    ASSERT_FALSE(expectedImage.empty());
    ASSERT_FALSE(receivedImage.empty());
    ASSERT_EQ(expectedImage.cols, receivedImage.cols);
    ASSERT_EQ(expectedImage.rows, receivedImage.rows);
    ASSERT_TRUE(expectedImage.type() == receivedImage.type());

    auto areIdentical = compareImage(expectedImage, receivedImage);
    EXPECT_TRUE(areIdentical);
}
}  // namespace bilberry::test