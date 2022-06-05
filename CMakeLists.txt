cmake_minimum_required(VERSION 3.8)
project(CBGdImage)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -static-libstdc++)

set(CBROTHER_ROOT XXXX/cbsdk)
set(GD_INCLUDE_DIR XXXX/libgd/src)
set(GD_BINARY_DIR XXXX/libgd/build/Bin/Release)

if (WIN32)
ADD_DEFINITIONS( -DWIN32 -D_WIN32 -DMSWIN32 -DBGDWIN32)
endif (WIN32)

include_directories(
	${CBROTHER_ROOT}/include
	${GD_INCLUDE_DIR}
)

link_directories(
	${GD_BINARY_DIR}
   )

add_library(CBGdImage SHARED
        ./CBGdImage.cpp
		)

target_link_libraries(${PROJECT_NAME} libgd_static)

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${LINK_FLAGS}" )

#add_definitions("-Wall -g")
