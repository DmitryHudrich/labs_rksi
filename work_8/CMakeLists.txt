cmake_minimum_required(VERSION 3.10)
project(danil_kostin_work_8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

get_property(work_projects_output_directory GLOBAL PROPERTY work_projects_output_directory)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${work_projects_output_directory}/${PROJECT_NAME})

set(SOURCE
    "square_matrix.h"
)

add_executable(${PROJECT_NAME} ${SOURCE} "main.cpp") 

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(TEST_FILES
  "tests/square_matrix_test.cpp"
)

add_executable(
  matrix_test
  ${TEST_FILES}
  ${SOURCE}
)

target_link_libraries(
  matrix_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(matrix_test)