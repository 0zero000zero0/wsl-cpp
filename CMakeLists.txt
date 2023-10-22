cmake_minimum_required(VERSION 3.10)
project(MyQtOpenCVProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(MyQtOpenCVProject main.cpp)
target_link_libraries(MyQtOpenCVProject Qt5::Widgets ${OpenCV_LIBS})
