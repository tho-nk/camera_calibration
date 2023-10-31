#include "Calibration.hpp"

#include <iostream>
#include <opencv2/opencv.hpp>

namespace bilberry::calibration {
Calibration::Calibration(/* args */) {}

Calibration::~Calibration() {}

void Calibration::run() {
    std::cout << "hello from Calibration" << std::endl;

    // Load an image from a file
    cv::Mat image = cv::imread(filePath.string());

    // Check if the image was loaded successfully
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image" << std::endl;
        return;
    }

    // Display the image in a window
    // cv::imshow("Loaded Image", image);

    // Save the image to a file
    cv::imwrite("/workspaces/bilberry/output.jpg", image);

    // Wait for a key press and then close the window
    // cv::waitKey(0);
    // cv::destroyAllWindows();
}
}  // namespace bilberry::calibration