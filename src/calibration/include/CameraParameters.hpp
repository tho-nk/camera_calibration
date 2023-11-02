#pragma once

namespace bilberry::calibration {

struct Aperture {
    double height{4.224};
    double width{5.632};
};

struct FieldOfView {
    double horizontal{39};
    double vertical{29.6};
};

struct CameraAndLensDistortion {
    double k1{-1.2093325853347778};
    double k2{-1.041786551475525};
    double k3{64.01393127441406};
    double k4{-0.5568028688430786};
    double k5{-3.6638600826263428};
    double k6{78.03067016601562};
    double p1{-0.004819112829864025};
    double p2{-0.0027203019708395004};
};

struct IntrinsicParameters {
    double cx{1280};
    double cy{960};
    double fx{3751.937744140625};
    double fy{3821.9775390625};
};

struct Resolution {
    double height{1920};
    double width{2560};
};

struct CameraParameters {
    Aperture aperture;
    FieldOfView fieldOfView;
    CameraAndLensDistortion cameraAndLensDistortion;
    IntrinsicParameters intrinsicParameters;
    Resolution resolution;
};

}  // namespace bilberry::calibration