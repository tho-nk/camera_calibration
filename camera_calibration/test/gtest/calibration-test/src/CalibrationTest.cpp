#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <vector>

#include "MockCameraManager.hpp"
#include "MockImageManager.hpp"
#include "UtilityTest.hpp"
#include "calibration/include/Calibration.hpp"

namespace bc = calibration;

namespace test {

struct CalibrationTestData {
    std::vector<cv::Point> points;
    cv::Point3d expectedCameraPosition;
};

class CalibrationBilberryTest : public ::testing::TestWithParam<CalibrationTestData> {
   protected:
    CalibrationBilberryTest()
        : mockImageManager(std::make_shared<MockImageManager>()),
          mockCameraManager(std::make_shared<MockCameraManager>()),
          calib(mockCameraManager)
    {
    }

    void SetUp() override {}

    std::shared_ptr<MockImageManager> mockImageManager;
    std::shared_ptr<MockCameraManager> mockCameraManager;

    bc::Calibration calib;
};

TEST_F(CalibrationBilberryTest, drawLineTest)
{
    const std::filesystem::path inputPath("./base-line/input.jpg");
    const std::filesystem::path expectedPath("./base-line/expectedLine.png");

    cv::Point start(738, 645);
    cv::Point end(1665, 621);
    cv::Scalar color(0, 0, 255);
    auto originalImage = cv::imread(inputPath);
    EXPECT_CALL(*mockImageManager, load(testing::_)).Times(1).WillOnce(testing::Return(originalImage));
    auto receivedImage = mockImageManager->load(inputPath);

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

TEST_F(CalibrationBilberryTest, drawMultiLineTest)
{
    const std::filesystem::path inputPath("./base-line/input.jpg");
    const std::filesystem::path expectedPath("./base-line/expectedRectangle.png");

    cv::Point p1(738, 645);
    cv::Point p2(1665, 621);
    cv::Point p3(1754, 1066);
    cv::Point p4(678, 1088);
    cv::Scalar color(0, 0, 255);

    auto originalImage = cv::imread(inputPath);
    EXPECT_CALL(*mockImageManager, load(testing::_)).Times(1).WillOnce(testing::Return(originalImage));

    auto receivedImage = mockImageManager->load(inputPath);

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

TEST_F(CalibrationBilberryTest, drawRectangleTest)
{
    const std::filesystem::path inputPath("./base-line/input.jpg");
    const std::filesystem::path expectedPath("./base-line/expectedRectangle.png");

    cv::Point p1(738, 645);
    cv::Point p2(1665, 621);
    cv::Point p3(1754, 1066);
    cv::Point p4(678, 1088);
    cv::Scalar color(0, 0, 255);

    auto originalImage = cv::imread(inputPath);
    EXPECT_CALL(*mockImageManager, load(testing::_)).Times(1).WillOnce(testing::Return(originalImage));

    auto receivedImage = mockImageManager->load(inputPath);

    calib.drawRectangle(receivedImage, {p1, p2, p3, p4}, color, 5);

    auto expectedImage = cv::imread(expectedPath.string());

    ASSERT_FALSE(expectedImage.empty());
    ASSERT_FALSE(receivedImage.empty());
    ASSERT_EQ(expectedImage.cols, receivedImage.cols);
    ASSERT_EQ(expectedImage.rows, receivedImage.rows);
    ASSERT_TRUE(expectedImage.type() == receivedImage.type());

    auto areIdentical = compareImage(expectedImage, receivedImage);
    EXPECT_TRUE(areIdentical);
}

TEST_F(CalibrationBilberryTest, getCameraPositionTest)
{
    std::vector<cv::Point> points{cv::Point(738, 645), cv::Point(1665, 621), cv::Point(1754, 1066),
                                  cv::Point(678, 1088)};
    bc::CameraParameters cameraParams;
    EXPECT_CALL(*mockCameraManager, getCameraParameters()).Times(1).WillOnce(testing::ReturnRef(cameraParams));
    auto cameraPosition = calib.computeCameraPosition(points);
    std::cout << "Camera Position (X, Y, Z): " << cameraPosition << std::endl;
    double tolerance = 1e-6;
    EXPECT_NEAR(cv::norm(cv::Point3d(0.0204516, -0.059663, -0.0277426) - cameraPosition), 0.0, tolerance);
}

INSTANTIATE_TEST_SUITE_P(CalibrationBilberryTestParameters, CalibrationBilberryTest,
                         ::testing::Values(CalibrationTestData{{cv::Point(738, 645), cv::Point(1665, 621),
                                                                cv::Point(1754, 1066), cv::Point(678, 1088)},
                                                               cv::Point3d(0.0204516, -0.059663, -0.0277426)},
                                           CalibrationTestData{{cv::Point(500, 500), cv::Point(1000, 500),
                                                                cv::Point(500, 1000), cv::Point(1000, 1000)},
                                                               cv::Point3d(0.129225, 0.0231686, -0.0284667)}));

TEST_P(CalibrationBilberryTest, CalibrationBilberryTestParameters)
{
    const auto& points = GetParam().points;
    const auto& expectedCameraPosition = GetParam().expectedCameraPosition;
    bc::CameraParameters cameraParams;
    EXPECT_CALL(*mockCameraManager, getCameraParameters()).Times(1).WillOnce(testing::ReturnRef(cameraParams));
    auto cameraPosition = calib.computeCameraPosition(points);
    std::cout << "Camera Position (X, Y, Z): " << cameraPosition << std::endl;
    double tolerance = 1e-6;
    EXPECT_NEAR(cv::norm(expectedCameraPosition - cameraPosition), 0.0, tolerance);
}

}  // namespace  test