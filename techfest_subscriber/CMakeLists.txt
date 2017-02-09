cmake_minimum_required(VERSION 3.5)
project(techfest_subscriber)
if(NOT WIN32)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra")
endif()
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs)

install(TARGETS ${PROJECT_NAME} DESTINATION ../bin)

ament_package()
