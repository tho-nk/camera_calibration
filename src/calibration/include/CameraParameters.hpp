#pragma once

namespace bilberry::calibration {

struct Aperture {
    double height;
    double width;
};

struct FieldOfView {
    double horizontal;
    double vertical;
};

struct CameraAndLensDistortion {
    double k1;
    double k2;
    double k3;
    double k4;
    double k5;
    double k6;
    double p1;
    double p2;
};

struct IntrinsicParameters {
    double cx;
    double cy;
    double fx;
    double fy;
};

struct Resolution {
    double height;
    double width;
};

struct CameraParameters {
    Aperture aperture;
    FieldOfView fieldOfView;
    CameraAndLensDistortion cameraAndLensDistortion;
    IntrinsicParameters intrinsicParameters;
    Resolution resolution;
};

}  // namespace bilberry::calibration