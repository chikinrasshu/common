cmake_minimum_required(VERSION 3.27)
project(chk_common VERSION 1.0.0)

set(chk_common_src 
    "common.cpp"
)

set(chk_common_hdr 
    "common.hpp"
    "list.hpp"
    "logging.hpp"
    "memory.hpp"
    "string.hpp"
    "types.hpp"
)

set(chk_common_pub )
set(chk_common_prv )

list(TRANSFORM chk_common_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/common/")
list(TRANSFORM chk_common_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/chk/common/")

add_library(chk_common ${chk_common_src} ${chk_common_hdr})
add_library(chk::common ALIAS chk_common)

target_compile_features(chk_common PUBLIC cxx_std_23)
target_include_directories(chk_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(chk_common PUBLIC ${chk_common_pub} PRIVATE ${chk_common_prv})
