cmake_minimum_required(VERSION 3.22)
project(massy)

include_directories(${BOOST_ROOT}/include)
include_directories(${SPDLOG_ROOT}/include)

add_subdirectory(massy/src)

set(PROJECT_SRC main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SRC})

target_link_libraries(
    ${PROJECT_NAME}
  # -L${BOOST_ROOT}/lib boost_system
  pthread
  communication
  ${OpenCV_LIBS})
