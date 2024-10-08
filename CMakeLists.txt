cmake_minimum_required(VERSION 3.20)

project(PBL2)

list(APPEND SOURCES "src/main.cpp" "src/food.cpp" "src/customer.cpp" "src/human.cpp")

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE include)