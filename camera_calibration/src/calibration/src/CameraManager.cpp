
#include "CameraManager.hpp"

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include <fstream>
#include <iostream>

namespace calibration {

CameraManager::CameraManager(const std::filesystem::path& configPath) : ICameraManager(), configPath_(configPath)
{
    load_();
}

void CameraManager::load_()
{
    std::ifstream jsonFile(configPath_.string());
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
    }

    // Parse the JSON
    std::string jsonContent((std::istreambuf_iterator<char>(jsonFile)), std::istreambuf_iterator<char>());
    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    // Check for parse errors
    if (document.HasParseError()) {
        std::cerr << "JSON parse error: " << rapidjson::GetParseErrorFunc(document.GetParseError()) << std::endl;
    }

    if (document.HasMember("aperture")) {
        const rapidjson::Value& apertureObject = document["aperture"];
        cameraParameters_.aperture.height = apertureObject["height"].GetDouble();
        cameraParameters_.aperture.width = apertureObject["width"].GetDouble();
    }

    if (document.HasMember("fieldOfView")) {
        const rapidjson::Value& fieldOfViewObject = document["fieldOfView"];
        cameraParameters_.fieldOfView.horizontal = fieldOfViewObject["horizontal"].GetDouble();
        cameraParameters_.fieldOfView.vertical = fieldOfViewObject["vertical"].GetDouble();
    }

    if (document.HasMember("distortion")) {
        const rapidjson::Value& distortionObject = document["distortion"];
        cameraParameters_.cameraAndLensDistortion.k1 = distortionObject["k1"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.k2 = distortionObject["k2"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.k3 = distortionObject["k3"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.k4 = distortionObject["k4"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.k5 = distortionObject["k5"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.k6 = distortionObject["k6"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.p1 = distortionObject["p1"].GetDouble();
        cameraParameters_.cameraAndLensDistortion.p2 = distortionObject["p2"].GetDouble();
    }

    if (document.HasMember("intrinsicParameters")) {
        const rapidjson::Value& intrinsicObject = document["intrinsicParameters"];
        cameraParameters_.intrinsicParameters.cx = intrinsicObject["cx"].GetDouble();
        cameraParameters_.intrinsicParameters.cy = intrinsicObject["cy"].GetDouble();
        cameraParameters_.intrinsicParameters.fx = intrinsicObject["fx"].GetDouble();
        cameraParameters_.intrinsicParameters.fy = intrinsicObject["fy"].GetDouble();
    }

    if (document.HasMember("resolution")) {
        const rapidjson::Value& resolutionObject = document["resolution"];
        cameraParameters_.resolution.height = resolutionObject["height"].GetDouble();
        cameraParameters_.resolution.width = resolutionObject["width"].GetDouble();
    }
}

CameraParameters const& CameraManager::getCameraParameters() const { return cameraParameters_; }

}  // namespace  calibration