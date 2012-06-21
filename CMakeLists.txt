CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
project (vmod_hello)

if (NOT MSVC)
	set (CMAKE_C_FLAGS "-std=c99")
endif ()

# add files to project
file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
file (GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
add_executable (vmod_hello ${src_files} ${header_files})