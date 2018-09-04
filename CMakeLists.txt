cmake_minimum_required(VERSION 3.11)

# Set language
project(simple-cpp-setup CXX)
# Set our standard version (here C++17)
set(CMAKE_CXX_STANDARD 17)
# Our CXXFLAGS. These flags will be propagated to all targets! If you want a
# specific targets to use a specific CXXFLAGS, use the following command
# target_compile_options(yourtarget [PRIVATE|PUBLIC] -myflag)
add_compile_options(-Wall -Wextra -pedantic)

# Generate a library containing everything. Only main should be left out for
# easy testing
add_library(simple-cpp-setup
  src/square.cpp
  src/square.hpp
)
# Include in PUBLIC so that we don't have to duplicate the line for everything
# that will use the lib. When include/link is in PUBLIC, the include/lib will
# propagate to all targets which links to it. Therefore, our executable will not
# have to target_include_directories as well as it is will be imported by
# linking to the lib.
target_include_directories(simple-cpp-setup PUBLIC src/)

# Our main program
add_executable(simple-cpp-setup-bin
  src/main.cpp
)
target_link_libraries(simple-cpp-setup-bin PRIVATE simple-cpp-setup)
# CMake can't handle two targets with the same name. The name the target of the
# binary with the suffix -bin, but update it's name when it's compiled without
# the suffix.
set_target_properties(simple-cpp-setup-bin
  PROPERTIES OUTPUT_NAME simple-cpp-setup
)

# Enable ctest
enable_testing()

# Our test program
add_executable(simple-cpp-setup_test
  tests/test.cpp
)
target_link_libraries(simple-cpp-setup_test PRIVATE simple-cpp-setup)

# Register the program with ctest
add_test(check simple-cpp-setup_test)
