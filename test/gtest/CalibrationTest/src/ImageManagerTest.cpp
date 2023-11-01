#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

#include "Utility.hpp"
#include "calibration/include/ImageManager.hpp"

namespace bc = bilberry::calibration;

namespace bilberry::test {

class ImageManagerTest : public ::testing::Test {
   protected:
    ImageManagerTest() : imageManagerUT(std::make_shared<bc::ImageManager>()) {}

    void SetUp() override {}

    std::shared_ptr<bc::ImageManager> imageManagerUT;
};

TEST_F(ImageManagerTest, loadTest)
{
    const std::filesystem::path inputPath("/workspaces/bilberry/base-line/input.jpg");
    auto loadedImage = imageManagerUT->load(inputPath);
    ASSERT_FALSE(loadedImage.empty());
    EXPECT_EQ(2560, loadedImage.cols);
    EXPECT_EQ(1920, loadedImage.rows);
}

TEST_F(ImageManagerTest, saveTest)
{
    const std::filesystem::path outputPath("received.png");
    cv::Mat imageToSave(100, 100, CV_8UC3, cv::Scalar(255, 0, 0));
    imageManagerUT->save(outputPath, imageToSave);
    ASSERT_TRUE(std::filesystem::exists(outputPath));

    cv::Mat savedImage = cv::imread(outputPath.string());
    ASSERT_FALSE(savedImage.empty());
    ASSERT_EQ(100, savedImage.cols);
    ASSERT_EQ(100, savedImage.rows);
    ASSERT_TRUE(imageToSave.type() == savedImage.type());
    auto areIdentical = compareImage(imageToSave, savedImage);
    EXPECT_TRUE(areIdentical);
}

}  // namespace bilberry::test