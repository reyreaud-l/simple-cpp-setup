cmake_minimum_required(VERSION 3.11)
set(PROJ simple-cpp-setup)

# Set language
project(${PROJ} CXX)

# Generate a library containing everything. Only main should be left out for
# easy testing
add_library(${PROJ}_LIB
  src/square.cpp
  src/square.hpp
)
# Include in PUBLIC so that we don't have to duplicate the line for everything
# that will use the lib.
target_include_directories(${PROJ}_LIB PUBLIC src/)

# Our main program
add_executable(${PROJ}
  src/main.cpp
)
target_link_libraries(${PROJ} PRIVATE ${PROJ}_LIB)

# Enable ctest
enable_testing()

# Our test program
add_executable(${PROJ}_test
  tests/test.cpp
)
add_test(check ${PROJ}_test)
target_link_libraries(${PROJ}_test PRIVATE ${PROJ}_LIB)
