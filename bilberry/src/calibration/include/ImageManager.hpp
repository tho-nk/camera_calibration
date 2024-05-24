#pragma once

#include "IImageManager.hpp"

namespace calibration {

class ImageManager : public IImageManager {
   public:
    ImageManager() = default;
    virtual ~ImageManager() = default;

    cv::Mat load(const std::filesystem::path& input) const override;
    void save(const std::filesystem::path& output, const cv::Mat& cvMat) const override;
};
}  // namespace  calibration