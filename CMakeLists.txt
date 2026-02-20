cmake_minimum_required(VERSION 3.20)
project(ACM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories("F:/下载/Compressed/boost_1_90_0")
file(GLOB CPP_FILES "*.cpp")

foreach(src ${CPP_FILES})
    get_filename_component(exe_name ${src} NAME_WE)
    add_executable(${exe_name} ${src})
endforeach()
