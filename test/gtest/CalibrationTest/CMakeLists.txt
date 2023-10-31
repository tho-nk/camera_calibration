cmake_minimum_required(VERSION 3.22)
project(CalibrationTest)


include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${SRC_PATH})


set(PROJECT_SRC
    CalibrationTest.cpp)

add_executable(${PROJECT_NAME}
    ${PROJECT_SRC})

target_link_libraries(${PROJECT_NAME}
    GTest::GTest GTest::Main
    ${OpenCV_LIBS}
    calibration)
                  