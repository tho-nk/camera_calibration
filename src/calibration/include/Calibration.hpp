#pragma once

#include <memory>
#include <opencv2/opencv.hpp>

#include "CameraManager.hpp"

namespace bilberry::calibration {
class Calibration {
   public:
    Calibration(const std::shared_ptr<ICameraManager>& cameraManager);
    ~Calibration();
    void drawLine(cv::Mat& image, const cv::Point& startPoint, const cv::Point& endPoint, const cv::Scalar& color,
                  int width);

    cv::Point3d computeCameraPosition(const std::vector<cv::Point>& points);

   private:
    std::shared_ptr<ICameraManager> cameraManager_;
};

}  // namespace bilberry::calibration