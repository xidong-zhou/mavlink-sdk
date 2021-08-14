CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
# project name
PROJECT(aimilink_sdk)

# message output
MESSAGE(STATUS "This is the BINARY dir: " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is the SOURCE dir: " ${PROJECT_SOURCE_DIR})

# add compile options
add_compile_options(-std=c++11)
add_compile_options(-fPIC)
add_compile_options(-pthread)
add_compile_options(-DASIO_STANDALONE)
add_compile_options(-DASIO_HAS_STD_CHRONO)

# include directories
INCLUDE_DIRECTORIES(
	${PROJECT_SOURCE_DIR}/include/legacy
	${PROJECT_SOURCE_DIR}/include/mavlink_protocol
	${PROJECT_SOURCE_DIR}/include/mavlink_protocol/common
)

# link directories

# set library output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# set the library file name
AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src LIB_DELTAROBOTCONTROL_SRC)

# add library
ADD_LIBRARY(aimilink_dynamic SHARED ${LIB_DELTAROBOTCONTROL_SRC})
ADD_LIBRARY(aimilink_static STATIC ${LIB_DELTAROBOTCONTROL_SRC})

# set library properties
SET_TARGET_PROPERTIES(aimilink_dynamic PROPERTIES OUTPUT_NAME "aimilink")
SET_TARGET_PROPERTIES(aimilink_dynamic PROPERTIES VERSION 1.1 SOVERSION 1)
SET_TARGET_PROPERTIES(aimilink_static PROPERTIES OUTPUT_NAME "aimilink")

# target link libraries
TARGET_LINK_LIBRARIES(aimilink_dynamic pthread)
TARGET_LINK_LIBRARIES(aimilink_static pthread)
