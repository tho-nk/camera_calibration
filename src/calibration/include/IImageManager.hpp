#pragma once
#include <filesystem>
#include <opencv2/opencv.hpp>
#include <string>

namespace bilberry::calibration {
class IImageManager {
   public:
    IImageManager() = default;
    virtual ~IImageManager() = default;

    virtual cv::Mat load(const std::filesystem::path& input) const = 0;
    virtual void save(const std::filesystem::path& output, const cv::Mat& cvMat) const = 0;
};
}  // namespace bilberry::calibration