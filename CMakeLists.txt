cmake_minimum_required(VERSION 3.20)

project (KeypressPublisherSubscriber
  DESCRIPTION "Demo how to turn blocking I/O into event callbacks"
  LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wconversion -Wextra -pedantic)
include(GNUInstallDirs)

add_executable(demoStdFunc demoStdFunc.cpp)
add_executable(demoInterface demoInterface.cpp)
add_executable(demo_blockingio demo_blockingio.cpp)
