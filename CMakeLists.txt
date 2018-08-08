cmake_minimum_required(VERSION 2.8)
project(buffer C CXX)

# set(default_build_type "Debug")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include_directories(${CMAKE_SOURCE_DIR})

find_package(Glog REQUIRED)
include_directories(SYSTEM ${GLOG_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${GLOG_LIBRARIES})

find_package(GFlags REQUIRED)
include_directories(SYSTEM ${GFLAGS_INCLUDE_DIRS})
list(APPEND LINKER_LIBS ${GFLAGS_LIBRARIES})

find_package(GTest REQUIRED)
include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})

find_package(GBenchmark REQUIRED)
include_directories(SYSTEM ${Benchmark_INCLUDE_DIRS})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g")
SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

file(GLOB_RECURSE CORE_SRC_FILES "src/*.cc")
add_library(core SHARED ${CORE_SRC_FILES})
target_link_libraries(core ${LINKER_LIBS})

set(TEST_FILES buffer_test)

foreach(f ${TEST_FILES})
  message(STATUS "Found test - " ${f})
  add_executable(${f} tests/${f}.cc)
  target_link_libraries(${f} core ${LINKER_LIBS} ${GTEST_LIBRARIES})
endforeach(f ${TEST_FILES})

set(BENCHMARK_FILES memcpy_benchmark)

foreach(f ${BENCHMARK_FILES})
  message(STATUS "Found benchmark - " ${f})
  add_executable(${f} benchmarks/${f}.cc)
  target_link_libraries(${f} core ${LINKER_LIBS} ${Benchmark_LIBRARIES})
endforeach(f ${BENCHMARK_FILES})
