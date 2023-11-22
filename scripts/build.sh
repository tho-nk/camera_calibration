export project_name=massy
export THIRD_PARTY=/home/ugitho/third-party
export Boost_Version='1.81.0'
export GoogleTest_Version='1.13.0'
export OpenCV_Version='4.8.0'
export Rapidjson_Version='1.1.0'
export SpdLog_Version='1.12.0'

cd ${project_name}

cmake -B build -DCMAKE_BUILD_TYPE=Debug
make -C build -j${nproc}