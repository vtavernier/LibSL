CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
 
IF(LIBSL_BUILD_GL)
ADD_SUBDIRECTORY(viewmesh)
ADD_SUBDIRECTORY(viewimage)
ENDIF(LIBSL_BUILD_GL)
IF(LIBSL_BUILD_DX9)
ADD_SUBDIRECTORY(uvatlas)
ADD_SUBDIRECTORY(viewfloat)
ENDIF(LIBSL_BUILD_DX9)
ADD_SUBDIRECTORY(imageedit)
ADD_SUBDIRECTORY(smoothmesh)

