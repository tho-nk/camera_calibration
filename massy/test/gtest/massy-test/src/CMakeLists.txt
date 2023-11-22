cmake_minimum_required(VERSION 3.22)
project(test-massy)


include_directories(${GOOGLE_TEST_ROOT}/include)
include_directories(${RAPIDJSON_ROOT}/include)
include_directories(${SRC_PATH})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

file(GLOB PROJECT_SRC *.cpp)


add_executable(${PROJECT_NAME}
    ${PROJECT_SRC})

target_link_libraries(${PROJECT_NAME}
    -L${GOOGLE_TEST_ROOT}/lib gtest gtest_main gmock gmock_main
    ${OpenCV_LIBS}
    communication)
                  