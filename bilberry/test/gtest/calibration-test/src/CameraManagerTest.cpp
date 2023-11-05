#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "UtilityTest.hpp"
#include "calibration/include/CameraManager.hpp"

namespace bc = bilberry::calibration;

namespace bilberry::test {

class CameraManagerTest : public ::testing::Test {
   protected:
    CameraManagerTest()
        : cameraManagerUT(std::make_shared<bc::CameraManager>("./configurations/camera-configuration.json"))
    {
    }

    void SetUp() override {}

    std::shared_ptr<bc::CameraManager> cameraManagerUT;
};

TEST_F(CameraManagerTest, loadConfigTest)
{
    auto cameraParameters = cameraManagerUT->getCameraParameters();
    EXPECT_DOUBLE_EQ(cameraParameters.aperture.height, 4.224);
    EXPECT_DOUBLE_EQ(cameraParameters.aperture.width, 5.632);
    EXPECT_DOUBLE_EQ(cameraParameters.fieldOfView.horizontal, 39);
    EXPECT_DOUBLE_EQ(cameraParameters.fieldOfView.vertical, 29.6);

    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k1, -1.2093325853347778);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k2, -1.041786551475525);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k3, 64.01393127441406);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k4, -0.5568028688430786);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k5, -3.6638600826263428);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.k6, 78.03067016601562);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.p1, -0.004819112829864025);
    EXPECT_DOUBLE_EQ(cameraParameters.cameraAndLensDistortion.p2, -0.0027203019708395004);

    EXPECT_DOUBLE_EQ(cameraParameters.intrinsicParameters.cx, 1280);
    EXPECT_DOUBLE_EQ(cameraParameters.intrinsicParameters.cy, 960);
    EXPECT_DOUBLE_EQ(cameraParameters.intrinsicParameters.fx, 3751.937744140625);
    EXPECT_DOUBLE_EQ(cameraParameters.intrinsicParameters.fy, 3821.9775390625);

    EXPECT_DOUBLE_EQ(cameraParameters.resolution.height, 1920);
    EXPECT_DOUBLE_EQ(cameraParameters.resolution.width, 2560);
}
}  // namespace bilberry::test