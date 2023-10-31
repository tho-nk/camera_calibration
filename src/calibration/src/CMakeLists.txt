project(calibration)

file(GLOB SOURCES "*.cpp" "*.h*")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

include_directories(
  ${OPENCV_ROOT}/include
  ${BOOST_ROOT}/include)

message(OPENCV_ROOT ${OPENCV_ROOT})
message(BOOST_ROOT ${BOOST_ROOT})

set(PROJECT_SRC Calibration.cpp)

add_library(${PROJECT_NAME} ${PROJECT_SRC})
