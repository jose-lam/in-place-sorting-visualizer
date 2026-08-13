cmake_minimum_required(VERSION 3.20)
project(in-place-sorting-visualizer CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/Sorter.cpp
    src/ShellSort.cpp
    src/HeapSort.cpp
    src/InsertionSort.cpp
    src/VisualizerApi.cpp
)


add_library(sorting_core ${SOURCES})
target_include_directories(sorting_core PUBLIC include)

add_executable(sorting_visualizer main.cpp)
target_link_libraries(sorting_visualizer PRIVATE sorting_core)
