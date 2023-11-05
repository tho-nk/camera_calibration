#include "UtilityTest.hpp"

#include <vector>

namespace bilberry::test {
bool compareImage(const cv::Mat& l, const cv::Mat& r, int channels)
{
    std::vector<cv::Mat> lChannels, rChannels;
    cv::split(l, lChannels);
    cv::split(r, rChannels);

    bool areIdentical = true;
    for (int i = 0; i < channels; i++) {
        cv::Mat channelDiff = lChannels[i] != rChannels[i];
        if (cv::countNonZero(channelDiff) != 0) {
            areIdentical = false;
            break;
        }
    }
    if (areIdentical) {
        std::cout << "The images are identical." << std::endl;
    }
    else {
        std::cout << "The images are not identical." << std::endl;
    }
    return areIdentical;
}
}  // namespace bilberry::test
