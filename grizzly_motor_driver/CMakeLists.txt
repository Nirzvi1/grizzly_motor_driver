cmake_minimum_required(VERSION 2.8.3)
project(grizzly_motor_driver)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES grizzly_motor_driver
  CATKIN_DEPENDS roscpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/driver.cpp
  src/interface.cpp
)

target_link_libraries(grizzly_motor_driver
  ${catkin_LIBRARIES}
)

add_executable(test_node src/main.cpp)

target_link_libraries(test_node
  grizzly_motor_driver
  ${catkin_LIBRARIES}
)

if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(test_can_frame test/test_can_frame.cpp)
  target_link_libraries(test_can_frame ${PROJECT_NAME})
endif()