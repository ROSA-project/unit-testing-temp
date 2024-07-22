cmake_minimum_required(VERSION 3.10)

project (RosaSimulator VERSION 0.1)

# make gtest link the runtimes dynamically
SET(gtest_force_shared_crt on CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")

# Add GoogleTest as a subdirectory
add_subdirectory(googletest)

# Include GoogleTest headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Include my headers
include_directories(src/utils)

# Add executables for the project
add_executable(
    ${PROJECT_NAME} 
    src/utils/sphereIntersection.cpp main.cpp
)

# Add executables for the tests
add_executable(
  test
  src/utils/sphereIntersection_test.cpp src/utils/sphereIntersection.cpp
)



target_link_libraries(test gtest_main)