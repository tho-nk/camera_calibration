#include "ImageManager.hpp"

namespace calibration {

cv::Mat ImageManager::load(const std::filesystem::path& input) const { return cv::imread(input.string()); }

void ImageManager::save(const std::filesystem::path& output, const cv::Mat& cvMat) const
{
    cv::imwrite(output.string(), cvMat, {cv::IMWRITE_JPEG_QUALITY, 100});
}

}  // namespace  calibration