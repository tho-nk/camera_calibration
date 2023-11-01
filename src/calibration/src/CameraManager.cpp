
#include "CameraManager.hpp"

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include <fstream>
#include <iostream>

namespace bilberry::calibration {

CameraParameters CameraManager::load(const std::filesystem::path& configPath)
{
    std::ifstream jsonFile(configPath.string());
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        std::clog << "default camera loaded" << std::endl;
        return CameraParameters();
    }

    // Parse the JSON
    std::string jsonContent((std::istreambuf_iterator<char>(jsonFile)), std::istreambuf_iterator<char>());
    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    // Check for parse errors
    if (document.HasParseError()) {
        std::cerr << "JSON parse error: " << rapidjson::GetParseErrorFunc(document.GetParseError()) << std::endl;
        std::clog << "default camera loaded" << std::endl;
        return CameraParameters();
    }

    // Create a CameraParameters structure and fill it from the parsed JSON
    CameraParameters cameraParams;
    if (document.HasMember("aperture")) {
        const rapidjson::Value& apertureObject = document["aperture"];
        cameraParams.aperture.height = apertureObject["height"].GetDouble();
        cameraParams.aperture.width = apertureObject["width"].GetDouble();
    }

    if (document.HasMember("fieldOfView")) {
        const rapidjson::Value& fieldOfViewObject = document["fieldOfView"];
        cameraParams.fieldOfView.horizontal = fieldOfViewObject["horizontal"].GetDouble();
        cameraParams.fieldOfView.vertical = fieldOfViewObject["vertical"].GetDouble();
    }

    if (document.HasMember("distortion")) {
        const rapidjson::Value& distortionObject = document["distortion"];
        cameraParams.cameraAndLensDistortion.k1 = distortionObject["k1"].GetDouble();
        cameraParams.cameraAndLensDistortion.k2 = distortionObject["k2"].GetDouble();
        cameraParams.cameraAndLensDistortion.k3 = distortionObject["k3"].GetDouble();
        cameraParams.cameraAndLensDistortion.k4 = distortionObject["k4"].GetDouble();
        cameraParams.cameraAndLensDistortion.k5 = distortionObject["k5"].GetDouble();
        cameraParams.cameraAndLensDistortion.k6 = distortionObject["k6"].GetDouble();
        cameraParams.cameraAndLensDistortion.p1 = distortionObject["p1"].GetDouble();
        cameraParams.cameraAndLensDistortion.p2 = distortionObject["p2"].GetDouble();
    }

    if (document.HasMember("intrinsicParameters")) {
        const rapidjson::Value& intrinsicObject = document["intrinsicParameters"];
        cameraParams.intrinsicParameters.cx = intrinsicObject["cx"].GetDouble();
        cameraParams.intrinsicParameters.cy = intrinsicObject["cy"].GetDouble();
        cameraParams.intrinsicParameters.fx = intrinsicObject["fx"].GetDouble();
        cameraParams.intrinsicParameters.fy = intrinsicObject["fy"].GetDouble();
    }

    if (document.HasMember("resolution")) {
        const rapidjson::Value& resolutionObject = document["resolution"];
        cameraParams.resolution.height = resolutionObject["height"].GetDouble();
        cameraParams.resolution.width = resolutionObject["width"].GetDouble();
    }
    return cameraParams;
}

}  // namespace bilberry::calibration