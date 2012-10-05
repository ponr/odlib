cmake_minimum_required (VERSION 2.8)

project (odlib)

# Use C++11
set(MY_CXXFLAGS "-std=c++0x")

if(APPLE)
    set(MY_CXXFLAGS "${MY_CXXFLAGS} -stdlib=libc++")
    link_libraries("-stdlib=libc++")
endif(APPLE)

set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall ${CMAKE_CXX_FLAGS_DEBUG} ${MY_CXXFLAGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${MY_CXXFLAGS}")
set(CMAKE_BUILD_TYPE debug)

# Find Boost
set(BOOSTCOMPONENTS system filesystem thread signals-mt)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.45.0 REQUIRED COMPONENTS ${BOOSTCOMPONENTS})
include_directories(${Boost_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED libglfw)
pkg_search_module(GLEW REQUIRED glew)
find_package(OpenGL REQUIRED)

find_package(Qt4 4.4.3 COMPONENTS QtCore QtGui QtOpenGL)
if(QT4_FOUND)
    include(${QT_USE_FILE})
endif(QT4_FOUND)

if(OPENGL_FOUND)
    add_definitions(-DOPENGL)
    include_directories(${OPENGL_INCLUDE_DIR})
    link_directories(${OPENGL_LIBRARY_DIR})
endif(OPENGL_FOUND)

if(GLFW_FOUND)
    message("-- Found GLFW")
    add_definitions(-DGLFW)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})
endif()

if(GLEW_FOUND)
    message("-- Found GLEW")
    add_definitions(-DGLEW)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_directories(${GLEW_LIBRARY_DIRS})
endif()

if(DEFINED ANDROID)
    add_definitions(-DANDROID)
endif()

if(DEFINED APPLE)
    add_definitions(-DAPPLE)
    find_library(COCOA_LIBRARY Cocoa REQUIRED)
    find_library(IOKIT_LIBRARY IOKit REQUIRED)
endif()

if(DEFINED LINUX)
    add_definitions(-DLINUX)
    find_package(OpenGL REQUIRED)
endif()

if(DEFINED WIN32)
    add_definitions(-DWINDOWS)
    add_definitions(-DWIN32)
endif()

if(DEFINED WIN64)
    add_definitions(-DWINDOWS)
    add_definitions(-DWIN64)
endif()

add_subdirectory(src)
add_subdirectory(examples)
#add_subdirectory(tests)
