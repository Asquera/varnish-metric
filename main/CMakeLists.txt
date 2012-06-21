# add files to project
file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.c)
file (GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./*.h)

add_executable (vmod_hello ${src_files} ${header_files})
target_link_libraries (vmod_hello metric)
add_dependencies (vmod_hello metric)
