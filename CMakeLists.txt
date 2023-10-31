cmake_minimum_required(VERSION 3.22)
project(bilberry LANGUAGES C CXX)

# Default Build Type to be Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# System dependencies
set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/third-party)
set(OPENCV_ROOT ${THIRD_PARTY}/opencv/opencv-4.8.0)
list(APPEND CMAKE_PREFIX_PATH ${OPENCV_ROOT})

set(BOOST_ROOT ${THIRD_PARTY}/boost/boost-1.81.0)
set(GOOGLE_TEST_ROOT ${THIRD_PARTY}/googletest/googletest-1.13.0)

find_package( OpenCV REQUIRED )

add_subdirectory(src)
#add_subdirectory(test/gtest)
