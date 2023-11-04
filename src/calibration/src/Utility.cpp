#include "Utility.hpp"

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>

#include <fstream>
#include <iostream>

namespace bilberry::calibration {
std::tuple<std::vector<cv::Point>, cv::Scalar> loadPoints(const std::filesystem::path& pointsPath)
{
    // create json validator
    // validate json

    std::vector<cv::Point> points;
    cv::Scalar color;
    std::ifstream jsonFile(pointsPath.string());
    if (!jsonFile.is_open()) {
        std::cerr << "Failed to open JSON file." << std::endl;
        return std::make_tuple(points, color);
    }

    // Parse the JSON
    std::string jsonContent((std::istreambuf_iterator<char>(jsonFile)), std::istreambuf_iterator<char>());
    rapidjson::Document document;
    document.Parse(jsonContent.c_str());

    // Check for parse errors
    if (document.HasParseError()) {
        std::cerr << "JSON parse error: " << rapidjson::GetParseErrorFunc(document.GetParseError()) << std::endl;
        return std::make_tuple(points, color);
    }

    const rapidjson::Value& pointsArray = document["points"];
    const rapidjson::Value& colorArray = document["color"];

    // Extract "points"
    for (rapidjson::SizeType i = 0; i < pointsArray.Size(); i++) {
        const rapidjson::Value& point = pointsArray[i];
        int px = point["px"].GetInt();
        int py = point["py"].GetInt();
        points.emplace_back(px, py);
    }

    // Extract "color"
    int b = colorArray[0].GetInt();
    int g = colorArray[1].GetInt();
    int r = colorArray[2].GetInt();
    color = cv::Scalar(b, g, r);

    return std::make_tuple(points, color);
}
}  // namespace bilberry::calibration