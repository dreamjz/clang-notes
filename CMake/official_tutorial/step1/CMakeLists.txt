cmake_minimum_required(VERSION 3.0)

# set the project name and version
project(Tutorial VERSION 1.0)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# specify the C++ standard
# should be above the call of add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable 
add_executable(Tutorial tutorial.c)

# link libm
# should be after add_executable
target_link_libraries(Tutorial m)


# should be end of CMakeLists file
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")

