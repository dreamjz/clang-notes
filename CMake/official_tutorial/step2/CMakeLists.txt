cmake_minimum_required(VERSION 3.0)

# set the project name and version
project(Tutorial VERSION 1.0)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code 
configure_file(TutorialConfig.h.in TutorialConfig.h)

# specify the C++ standard
# should be above the call of add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the MathFunctions library
add_subdirectory(MathFunctions)

# add the executable 
add_executable(Tutorial tutorial.cxx)

# link libm
# should be after add_executable
target_link_libraries(Tutorial m)


# should be end of CMakeLists file
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}" 
                            "${PROJECT_SOURCE_DIR}/MathFunctions")


