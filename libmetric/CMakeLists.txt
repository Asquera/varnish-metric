file (GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} metric/*.c)
file (GLOB_RECURSE src_headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} metric/*.h)

check_include_files(sys/socket.h HAVE_SYS_SOCKET_H)

add_library (metric ${src_files} ${src_headers})