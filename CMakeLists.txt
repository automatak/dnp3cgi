cmake_minimum_required (VERSION 2.8)
project (dnp3decode)
set(DNP3DECODE_MAJOR_VERSION 2)
set(DNP3DECODE_MINOR_VERSION 1)
set(DNP3DECODE_MICRO_VERSION 0)
set(DNP3DECODE_VERSION ${DNP3DECODE_MAJOR_VERSION}.${DNP3DECODE_MINOR_VERSION}.${DNP3DECODE_MICRO_VERSION})

# other options off-by-default that you can enable
option(WERROR "Set all warnings to errors" OFF)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
# different release and debug flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
  
# ---- decoder exe
file(GLOB_RECURSE dnp3decode_SRC ./src/*.cpp)
add_executable(dnp3decode ${dnp3decode_SRC})
target_link_libraries (dnp3decode opendnp3 openpal cgicc)

