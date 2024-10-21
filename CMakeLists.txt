cmake_minimum_required(VERSION 3.20)

project(PBL2)

list(APPEND SOURCES "src/main.cpp"
                    "src/food.cpp"
                    "src/customer.cpp"
                    "src/human.cpp"
                    "src/employee.cpp"
                    "src/system_manager.cpp"
                    "src/computer.cpp"
                    "src/device.cpp"
                    "src/service.cpp"
                    "src/hire_computer.cpp"
                    "src/order_food.cpp")

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE include)