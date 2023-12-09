cmake_minimum_required(VERSION 3.10)

project(danil_kostin_work_7)

get_property(work_projects_output_directory GLOBAL PROPERTY work_projects_output_directory)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${work_projects_output_directory}/${PROJECT_NAME})

set(SOURCE
    "main.cpp"
    "program.h"
    "src/program.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCE})