#pragma once

#include <filesystem>
#include <opencv2/opencv.hpp>
#include <tuple>
#include <vector>

namespace bilberry::calibration {
std::tuple<std::vector<cv::Point>, cv::Scalar> loadPoints(const std::filesystem::path& pointsPath);
}  // namespace bilberry::calibration