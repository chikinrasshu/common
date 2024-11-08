cmake_minimum_required(VERSION 3.27)
project(chk_common)

################
# Dependencies #
################

set(chk_common_pub_libs )
set(chk_common_prv_libs )

##########################
# Platform agnostic code #
##########################

set(chk_common_hdr "common.hpp" "function.hpp" "logging.hpp" "source_loc.hpp" "string.hpp" "types.hpp")
set(chk_common_src "common.cpp" "logging.cpp")

list(TRANSFORM chk_common_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/chk/common/")
list(TRANSFORM chk_common_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/common/")

################################
# Build the library/executable #
################################

add_library(chk_common ${chk_common_src} ${chk_common_hdr})
target_include_directories(chk_common PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_compile_features(chk_common PUBLIC cxx_std_23)
target_compile_definitions(chk_common PUBLIC "CHK_COMMON_VERSION=\"${CMAKE_PROJECT_VERSION}\"")
target_compile_definitions(chk_common PRIVATE "CHK_PROJECT_BASE=\"${CMAKE_CURRENT_SOURCE_DIR}\"")

target_link_libraries(chk_common PUBLIC ${chk_common_pub_libs} PRIVATE ${chk_common_prv_libs})

###################
# Build the tests #
###################

set(chk_common_test_hdr "")
set(chk_common_test_src "main.cpp")

list(TRANSFORM chk_common_test_hdr PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/include/chk/common_test/")
list(TRANSFORM chk_common_test_src PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/src/common_test/")

add_executable(chk_common_test ${chk_common_test_src} ${chk_common_test_hdr})
target_include_directories(chk_common_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_compile_features(chk_common_test PUBLIC cxx_std_23)
target_compile_definitions(chk_common_test PUBLIC "CHK_COMMON_TEST_VERSION=\"${CMAKE_PROJECT_VERSION}\"")
target_compile_definitions(chk_common_test PRIVATE "CHK_PROJECT_BASE=\"${CMAKE_CURRENT_SOURCE_DIR}\"")

target_link_libraries(chk_common_test PUBLIC chk_common)
