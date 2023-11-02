#include "Calibration.hpp"

#include <algorithm>
#include <iostream>
#include <opencv2/opencv.hpp>

namespace bilberry::calibration {
Calibration::Calibration(const std::shared_ptr<ICameraManager>& cameraManager) : cameraManager_(cameraManager) {}

Calibration::~Calibration() {}

void Calibration::drawLine(cv::Mat& image, const cv::Point& startPoint, const cv::Point& endPoint,
                           const cv::Scalar& color, int width)
{
    std::cout << __FILE__ << ", " << __LINE__ << std::endl;
    cv::line(image, startPoint, endPoint, color, width, cv::LINE_AA);
}

cv::Point3d Calibration::computeCameraPosition(const std::vector<cv::Point>& points)
{
    // Create object points in the camera coordinate system
    const auto& cameraParams(cameraManager_->getCameraParameters());
    std::vector<cv::Point3d> objectPoints;
    std::transform(
        points.begin(), points.end(), std::back_inserter(objectPoints), [&cameraParams](const cv::Point& item) {
            return cv::Point3d((item.x - cameraParams.intrinsicParameters.cx) / cameraParams.intrinsicParameters.fx,
                               (item.y - cameraParams.intrinsicParameters.cy) / cameraParams.intrinsicParameters.fy,
                               1.0);
        });

    std::vector<cv::Point2f> imagePoints;
    std::transform(points.begin(), points.end(), std::back_inserter(imagePoints),
                   [](const cv::Point& item) { return cv::Point2f(item.x, item.y); });
    // Camera matrix (intrinsic parameters)
    cv::Mat cameraMatrix =
        (cv::Mat_<double>(3, 3) << cameraParams.intrinsicParameters.fx, 0, cameraParams.intrinsicParameters.cx, 0,
         cameraParams.intrinsicParameters.fy, cameraParams.intrinsicParameters.cy, 0, 0, 1);

    // Distortion coefficients
    cv::Mat distortionCoeffs = (cv::Mat_<double>(5, 1) << cameraParams.cameraAndLensDistortion.k1,
                                cameraParams.cameraAndLensDistortion.k2, cameraParams.cameraAndLensDistortion.p1,
                                cameraParams.cameraAndLensDistortion.p2, cameraParams.cameraAndLensDistortion.k3);

    // Rotation vector and translation vector
    cv::Mat rVec;  // Rotation vector
    cv::Mat tVec;  // Translation vector

    // Solve for pose using solvePnP
    cv::solvePnP(objectPoints, imagePoints, cameraMatrix, distortionCoeffs, rVec, tVec, false, cv::SOLVEPNP_SQPNP);

    // Convert rotation vector to rotation matrix
    cv::Mat rotationMatrix;
    cv::Rodrigues(rVec, rotationMatrix);

    // Extract camera position from translation vector
    cv::Point3d cameraPosition(tVec.at<double>(0), tVec.at<double>(1), tVec.at<double>(2));

    return cameraPosition;
}

}  // namespace bilberry::calibration