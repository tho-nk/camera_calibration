project(calibration)

file(GLOB PROJECT_SRC *.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${BOOST_ROOT}/include)

message(OpenCV_INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS})
message(BOOST_ROOT ${BOOST_ROOT})

# set(PROJECT_SRC Calibration.cpp)

add_library(${PROJECT_NAME} ${PROJECT_SRC})
