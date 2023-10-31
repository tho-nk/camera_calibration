#pragma once

#include <memory>

#include "CameraConfiguration.hpp"
#include "ImageManager.hpp"

namespace bilberry::calibration {
class Calibration {
   public:
    Calibration(const std::shared_ptr<IImageManager>& imageManager,
                const std::shared_ptr<ICameraConfiguration>& cameraConfiguration);
    ~Calibration();
    void drawLine(cv::Mat& image, const cv::Point& startPoint, const cv::Point& endPoint, const cv::Scalar& color,
                  int width);

    cv::Mat load(const std::filesystem::path& input);
    void save(const std::filesystem::path& output, const cv::Mat& cvMat);

   private:
    std::shared_ptr<ICameraConfiguration> cameraConfiguration_;
    std::shared_ptr<IImageManager> imageManager_;
};

}  // namespace bilberry::calibration