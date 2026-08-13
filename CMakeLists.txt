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

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sorting_core)

enable_testing()
add_executable(sorting_tests tests/test_sorting.cpp)
target_link_libraries(sorting_tests PRIVATE sorting_core)
add_test(NAME SortingCorrectnessTest COMMAND sorting_tests)
