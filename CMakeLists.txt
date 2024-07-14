cmake_minimum_required(VERSION 3.10)

project (RosaSimulator VERSION 0.1)

# Add GoogleTest as a subdirectory
add_subdirectory(googletest)

# Include GoogleTest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Include my headers
include_directories(src/utils)

# Add executables for the project
add_executable(
    ${PROJECT_NAME} 
    src/utils/geometry_functions.cpp main.cpp
)

# Add executables for the tests
add_executable(
  hello_test
  src/utils/geometry_functions_test.cpp src/utils/geometry_functions.cpp
)

target_link_libraries(hello_test gtest_main)