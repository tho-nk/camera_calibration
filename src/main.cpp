#include <iostream>

#include "calibration/include/Calibration.hpp"
#include "calibration/include/CameraManager.hpp"
#include "calibration/include/ImageManager.hpp"

namespace bc = bilberry::calibration;

int main() {
    std::cout << "Hello from bilberry" << std::endl;
    std::shared_ptr<bc::IImageManager> imageManager = std::make_shared<bc::ImageManager>();
    std::shared_ptr<bc::ICameraManager> cameraManager = std::make_shared<bc::CameraManager>();

    bc::Calibration aCal(imageManager, cameraManager);
    // aCal.drawLine();
    return 0;

}  // namespace