project(communication)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include/communication)

file(GLOB PROJECT_SRC *.cpp)

add_library(${PROJECT_NAME} ${PROJECT_SRC})
