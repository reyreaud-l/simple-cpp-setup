# Simple C++ Setup.

This repository contains a very simple C++ setup using CMake to build, and CTest
to test it.


To build: `mkdir build && cd build && cmake .. && make`

To test: `cd build && ctest`

## But why ?

Because we prefer code over builds.

I've seen many people simply not knowing where to start. Or just writing
horribles makefiles (To be honest, nobody knows how to cleanly write a simple
makefile). So I made this simple setup to allows anyone to freely copy the setup
to start coding, and not start fighting with build systems.

Enjoy!
