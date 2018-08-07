cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

project(CCalc)

include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/libmath)
include_directories(${CMAKE_SOURCE_DIR}/liblog)

add_executable(CCalc ${CMAKE_SOURCE_DIR}/libmath/libmath.cpp ${CMAKE_SOURCE_DIR}/liblog/liblog.cpp ${CMAKE_SOURCE_DIR}/calc/main.cpp)
