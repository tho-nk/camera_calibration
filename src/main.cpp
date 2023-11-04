#include <algorithm>
#include <csignal>
#include <iostream>
#include <string>

#include "calibration/include/Calibration.hpp"
#include "calibration/include/CameraManager.hpp"
#include "calibration/include/ImageManager.hpp"
#include "calibration/include/Utility.hpp"

namespace bc = bilberry::calibration;

void signalHandler(int signal)
{
    std::clog << "[CALIB] signal handling" << std::endl;
    exit(0);
}

int main()
{
    std::clog << "[CALIB] Calibration" << std::endl;
    signal(SIGINT, signalHandler);

    const std::filesystem::path inputPath("./base-line/input.jpg");
    const std::filesystem::path outputPath("./base-line/drawed-rectangle.jpg");
    const std::filesystem::path pointsPath("./data/image-points.json");
    std::shared_ptr<bc::IImageManager> imageManager = std::make_shared<bc::ImageManager>();
    std::shared_ptr<bc::ICameraManager> cameraManager =
        std::make_shared<bc::CameraManager>("./configurations/camera-configuration.json");
    bc::Calibration calib(cameraManager);

    try {
        while (true) {
            std::string userInput;

            std::cout << "Do you want to compute camera position? (yes/no): ";
            std::cin >> userInput;
            std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
            if (userInput == "YES" or userInput == "Y") {
                auto image = imageManager->load(inputPath);
                // load points from user
                // use file for better illustration
                const auto& [points, color] = bc::loadPoints(pointsPath);;
                calib.drawRectangle(image, points, color, 5);
                imageManager->save(outputPath, image);
                auto cameraPosition = calib.computeCameraPosition(points);
                std::cout << "Camera Position (X, Y, Z): " << cameraPosition << std::endl;
            }
            else {
                break;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;

}  // namespace