# - Find GLM
# Find the GLM headers
#
# GLM_INCLUDE_DIR - where to find the GLM headers
# GLM_FOUND       - True if GLM is found

if (GLM_INCLUDE_DIR)
  # already in cache, be silent
  set (GLM_FIND_QUIETLY TRUE)
endif (GLM_INCLUDE_DIR)

# find the headers
find_path (GLM_INCLUDE_PATH glm/glm.hpp
  PATHS
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_INSTALL_PREFIX}/include
  )

# handle the QUIETLY and REQUIRED arguments and set GLM_FOUND to
# TRUE if all listed variables are TRUE
include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (GLM "GLM could not be found. Set GLM_INC_DIR to point to the headers." GLM_INCLUDE_PATH)

if (GLM_FOUND)
  set (GLM_INCLUDE_DIR ${GLM_INCLUDE_PATH})
endif (GLM_FOUND)

mark_as_advanced(GLM_INCLUDE_PATH)
