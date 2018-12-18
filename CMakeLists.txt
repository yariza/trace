cmake_minimum_required(VERSION 3.1)

project( trace )

# Add directory with macros
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake )

# Add cmake file with useful functions
include( Common )

# automatic build type generator that provides sane defaults
include( BuildType )

set( COMPILE_FLAGS "-Wall -O2 -msse2" )
set( LINK_FLAGS    "" )

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

include_directories( ${PROJECT_SOURCE_DIR}/include )

append_files( Headers "h" src )
append_files( Sources "cpp" src )

include_directories( src )

add_executable(trace ${Sources} )
