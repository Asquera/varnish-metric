CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
project (vmod_hello)

if (NOT MSVC)
	set (CMAKE_C_FLAGS "-std=c99")
endif ()

message (STATUS "libs")
message (STATUS "    metric")
add_subdirectory (libmetric)

message (STATUS "apps")
message (STATUS "    main")
add_subdirectory (main)