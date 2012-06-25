CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
project (vmod_hello)

include (CheckIncludeFiles)

if (NOT MSVC)
    set (CMAKE_C_FLAGS "-std=c99 -D_POSIX_SOURCE")
    # set (CMAKE_REQUIRED_DEFINITIONS ${CMAKE_REQUIRED_DEFINITIONS} -D_GNU_SOURCE)
endif ()

message (STATUS "libs")
message (STATUS "    metric")
include_directories (libmetric)
add_subdirectory (libmetric)

message (STATUS "apps")
message (STATUS "    main")
add_subdirectory (main)