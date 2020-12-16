cmake_minimum_required (VERSION 2.8)
project (dnp3cgi)
set(DNP3CGI_MAJOR_VERSION 3)
set(DNP3CGI_MINOR_VERSION 1)
set(DNP3CGI_MICRO_VERSION 0)
set(DNP3CGI_VERSION ${DNP3CGI_MAJOR_VERSION}.${DNP3CGI_MINOR_VERSION}.${DNP3CGI_MICRO_VERSION})

# other options off-by-default that you can enable
option(WERROR "Set all warnings to errors" OFF)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
# different release and debug flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
  
# ---- decoder exe
file(GLOB_RECURSE dnp3cgi_SRC ./src/*.cpp)
add_executable(dnp3cgi ${dnp3cgi_SRC})
target_link_libraries (dnp3cgi opendnp3 cgicc)

