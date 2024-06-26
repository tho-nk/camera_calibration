cmake_minimum_required(VERSION 3.22)
project(camera_calibration LANGUAGES C CXX)

# Default Build Type to be Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
# Set the CMP0144 policy to NEW
# cmake_policy(SET CMP0144 NEW)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../package)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(THIRD_PARTY "$ENV{THIRD_PARTY}")
set(Boost_Version "$ENV{Boost_Version}")
set(BOOST_ROOT ${THIRD_PARTY}/boost/boost-${Boost_Version})

set(GoogleTest_Version "$ENV{GoogleTest_Version}")
set(GOOGLE_TEST_ROOT ${THIRD_PARTY}/googletest/googletest-${GoogleTest_Version})

set(OpenCV_Version "$ENV{OpenCV_Version}")
set(OPENCV_ROOT ${THIRD_PARTY}/opencv/opencv-${OpenCV_Version})
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_ROOT})
find_package( OpenCV REQUIRED )

set(Rapidjson_Version "$ENV{Rapidjson_Version}")
set(RAPIDJSON_ROOT ${THIRD_PARTY}/rapidjson/rapidjson-${Rapidjson_Version})


set(SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(test/gtest)
