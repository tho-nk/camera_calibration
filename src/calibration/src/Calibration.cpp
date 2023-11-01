#include "Calibration.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

namespace bilberry::calibration {
Calibration::Calibration(const std::shared_ptr<IImageManager>& imageManager,
                         const std::shared_ptr<ICameraConfiguration>& cameraConfiguration)
    : cameraConfiguration_(cameraConfiguration), imageManager_(imageManager)
{
}

Calibration::~Calibration() {}

void Calibration::drawLine(cv::Mat& image, const cv::Point& startPoint, const cv::Point& endPoint,
                           const cv::Scalar& color, int width)
{
    std::cout << __FILE__ << ", " << __LINE__ << std::endl;
    cv::line(image, startPoint, endPoint, color, width, cv::LINE_AA);
}

cv::Mat Calibration::load(const std::filesystem::path& input) { return imageManager_->load(input); }

void Calibration::save(const std::filesystem::path& output, const cv::Mat& cvMat)
{
    imageManager_->save(output, cvMat);
}

}  // namespace bilberry::calibration