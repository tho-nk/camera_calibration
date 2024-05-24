#pragma once

#include <opencv2/opencv.hpp>

namespace test {
bool compareImage(const cv::Mat& l, const cv::Mat& r, int channels = 3);
}  // namespace  test
