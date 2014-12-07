# author : ambreen2006@gmail.com
# developed with gcc 4.8 
# note: select toolchain using "sudo update-alternatives --config gcc"
 
cmake_minimum_required(VERSION 2.8.11)
project(basic_exercises)

macro(addflags)
  enable_language("CXX")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endmacro()

addflags()

set(GTEST_INCLUDE_DIR "/usr/local/include")
set(GTEST_LIBS_DIR "/usr/local/lib/gtest_main.a")
set(GMOCK_LIBS_DIR "/usr/local/lib/gmock_main.a")

add_subdirectory(mb_ds)
add_subdirectory(userapp)
add_subdirectory(mb_algorithms)