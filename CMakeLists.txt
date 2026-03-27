cmake_minimum_required(VERSION 3.8)
project(hi_filter)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
 
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  #set(ament_cmake_cpplint_FOUND TRUE)
  #ament_lint_auto_find_test_dependencies()
endif()

find_package(ament_lint_auto REQUIRED)
find_package(rclcpp)
find_package(sensor_msgs)
find_package(PCL REQUIRED)
find_package(pcl_conversions REQUIRED) 

add_executable(hi_filter src/hi_filter_node.cpp)
ament_target_dependencies(hi_filter rclcpp sensor_msgs pcl_conversions)

install(TARGETS
  hi_filter
  DESTINATION lib/${PROJECT_NAME})

ament_package()
