cmake_minimum_required(VERSION 3.27)
project(chk_common VERSION 1.0.0)

####################
### Dependencies ###
####################

include(FetchContent)

FetchContent_Declare(fmt GIT_REPOSITORY https://github.com/fmtlib/fmt GIT_TAG "origin/master" GIT_PROGRESS TRUE)
FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog GIT_TAG "origin/v1.x" GIT_PROGRESS TRUE)

set(SPDLOG_FMT_EXTERNAL TRUE CACHE BOOL "Use External fmt library")

FetchContent_MakeAvailable(fmt spdlog)

##############
### Common ###
##############

set(chk_common_src 
    "common.cpp"
)

set(chk_common_hdr 
    "common.hpp"
    "function.hpp"
    "list.hpp"
    "logging.hpp"
    "memory.hpp"
    "string.hpp"
    "types.hpp"
)

set(chk_common_pub fmt::fmt spdlog::spdlog)
set(chk_common_prv )

list(TRANSFORM chk_common_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/common/")
list(TRANSFORM chk_common_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/chk/common/")

add_library(chk_common ${chk_common_src} ${chk_common_hdr})
add_library(chk::common ALIAS chk_common)

target_compile_features(chk_common PUBLIC cxx_std_20)
target_include_directories(chk_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(chk_common PUBLIC ${chk_common_pub} PRIVATE ${chk_common_prv})

############
### Test ###
############

set(chk_common_test_src "main.cpp")
set(chk_common_test_hdr )

set(chk_common_test_pub chk::common)
set(chk_common_test_prv )

list(TRANSFORM chk_common_test_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/common_test/")
list(TRANSFORM chk_common_test_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/chk/common_test/")

add_executable(chk_common_test ${chk_common_test_src} ${chk_common_test_hdr})

target_compile_features(chk_common_test PUBLIC cxx_std_20)
target_include_directories(chk_common_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(chk_common_test PUBLIC ${chk_common_test_pub} PRIVATE ${chk_common_test_prv})
