cmake_minimum_required (VERSION 2.8)
project (odlib)

set(BOOSTCOMPONENTS system filesystem thread)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.45.0 REQUIRED COMPONENTS ${BOOSTCOMPONENTS})
include_directories(${Boost_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED libglfw)
pkg_search_module(GLEW REQUIRED glew)

if(GLFW_FOUND)
    message(status "Found GLFW")
    add_definitions(-DGLFW)
    include_directories(${GLFW_INCLUDE_DIRS})
endif()

if(GLEW_FOUND)
    message(status "Found GLEW")
    add_definitions(-DGLEW)
    include_directories(${GLEW_INCLUDE_DIRS})
endif()

if(DEFINED ANDROID)
    add_definitions(-DANDROID)
endif()

if(DEFINED APPLE)
    add_definitions(-DAPPLE)
endif()

if(DEFINED LINUX)
    add_definitions(-DLINUX)
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
