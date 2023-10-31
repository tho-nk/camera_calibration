cmake_minimum_required(VERSION 3.22)
project(bilberry)

add_subdirectory(calibration/src)

set(PROJECT_SRC main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_link_libraries(
  ${PROJECT_NAME}
  -L${BOOST_ROOT}/lib boost_system
  pthread
  calibration
  ${OpenCV_LIBS})
