#include <iostream>

#include "calibration/include/Calibration.hpp"
#include "calibration/include/CameraConfiguration.hpp"
#include "calibration/include/ImageManager.hpp"

namespace bc = bilberry::calibration;

int main() {
    std::cout << "Hello from bilberry" << std::endl;
    std::shared_ptr<bc::IImageManager> imageManager = std::make_shared<bc::ImageManager>();
    std::shared_ptr<bc::ICameraConfiguration> cameraConfiguration = std::make_shared<bc::CameraConfiguration>();

    bc::Calibration aCal(imageManager, cameraConfiguration);
    // aCal.drawLine();
    return 0;

}  // namespace