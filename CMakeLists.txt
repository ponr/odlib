cmake_minimum_required (VERSION 2.8)
project (odlib)

set(BOOSTCOMPONENTS system filesystem thread)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.45.0 REQUIRED COMPONENTS ${BOOSTCOMPONENTS})
include_directories(${Boost_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED libglfw)
pkg_search_module(GLEW REQUIRED glew)
find_package(OpenGL REQUIRED)

if(OPENGL_FOUND)
    add_definitions(-DOPENGL)
    include_directories(${OPENGL_INCLUDE_DIR})
    link_directories(${OPENGL_LIBRARY_DIR})
endif(OPENGL_FOUND)

if(GLFW_FOUND)
    message(status "Found GLFW")
    add_definitions(-DGLFW)
    include_directories(${GLFW_INCLUDE_DIRS})
    link_directories(${GLFW_LIBRARY_DIRS})
endif()

if(GLEW_FOUND)
    message(status "Found GLEW")
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
#add_subdirectory(tests)
