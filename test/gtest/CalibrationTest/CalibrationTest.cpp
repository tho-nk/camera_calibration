#include <gmock/gmock.h>

#include "calibration/include/Calibration.hpp"

TEST(CalibrationTest, TestCalibrationTest) {
    bilberry::calibration::Calibration aCal;
    aCal.run();
    EXPECT_EQ(200, 20);
}
