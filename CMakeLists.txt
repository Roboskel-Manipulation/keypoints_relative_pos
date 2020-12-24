cmake_minimum_required(VERSION 3.0.2)
project(keypoints_relative_pos)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  keypoint_3d_matching_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES keypoints_relative_pos
#  CATKIN_DEPENDS keypoint_3d_matching_msgs roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable (keypoints_relative_pos src/keypoints_relative_pos.cpp)
target_link_libraries (keypoints_relative_pos ${catkin_LIBRARIES})

