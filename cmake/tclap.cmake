# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install TCLAP
ExternalProject_Add(
    tclap
    URL https://downloads.sourceforge.net/project/tclap/tclap-1.2.2.tar.gz
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/tclap
    # Disable install step
    CONFIGURE_COMMAND ""
    INSTALL_COMMAND ""
    BUILD_COMMAND ""
)

ExternalProject_Get_Property( tclap source_dir binary_dir )

set ( TCLAP_INCLUDE_DIR ${source_dir}/include )
set ( TCLAP_FOUND true )
