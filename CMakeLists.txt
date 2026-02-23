cmake_minimum_required(VERSION 3.20)
project(ACM LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories("F:/下载/Compressed/boost_1_90_0")
file(GLOB CPP_FILES "*.cpp")

foreach(src ${CPP_FILES})
    get_filename_component(exe_name ${src} NAME_WE)
    add_executable(${exe_name} ${src}
            "c++/数据结构/二叉树/U81904 【模板】树的直径.cpp"
            "c++/数据结构/二叉树/P3304 [SDOI2013] 直径.cpp"
            "c++/算法/前缀和，差分，离散化/Code_1_303. 区域和检索 - 数组不可变.cpp"
            c++/算法/前缀和，差分，离散化/code_2_未排序数组中累加和为给定值的最长子数组长度.cpp
            "c++/算法/前缀和，差分，离散化/Code_3_560. 和为 K 的子数组.cpp"
            c++/算法/前缀和，差分，离散化/Code_4_未排序数组中累加和为给定值的最长子数组系列问题补1.cpp
            "c++/算法/前缀和，差分，离散化/Code_5_1124. 表现良好的最长时间段.cpp"
            "c++/算法/前缀和，差分，离散化/Code_6_1590. 使数组和能被 P 整除.cpp"
            "c++/算法/前缀和，差分，离散化/Code_7_1371. 每个元音包含偶数次的最长子字符串.cpp"
            "c++/算法/前缀和，差分，离散化/一维/差分/Code_1_1109. 航班预订统计.cpp"
            "c++/算法/前缀和，差分，离散化/一维/差分/P4231 三步必杀.cpp"
            "c++/算法/前缀和，差分，离散化/一维/差分/P5026 Lycanthropy.cpp")
endforeach()
