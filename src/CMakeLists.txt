
set(CMAKE_CXX_FLAGS "-Wall")

# Module: Core
#

# Source files for core module
set(OD_CORE_SRC
    od/core/types.hpp
    )

#add_library(od_core SHARED ${OD_CORE_SRC})

# Module: Event
#

# Source files for event module
set(OD_EVENT_SRC
    od/event/EventManager.cpp
    od/event/EventManager.hpp
    )

set(OD_EVENT_LIBRARIES "" )

add_library(od_event SHARED ${OD_EVENT_SRC})
target_link_libraries(od_event ${OD_EVENT_LIBRARIES})

# Module: Platform
#

# Source files for platform module
set(OD_PLATFORM_SRC
    od/platform/ApplicationFactory.cpp
    od/platform/ApplicationFactory.hpp
    od/platform/Application.cpp
    od/platform/Application.hpp
    od/platform/Window.cpp
    od/platform/Window.hpp
    od/platform/GLWindow.cpp
    od/platform/GLWindow.hpp
    )

set(OD_PLATFORM_LIBRARIES "od_graphics" )

# Link against OpenGL libraries if present
if(OPENGL_FOUND)
    # Link against Qt4
    if(QT4_FOUND)
        set(OD_PLATFORM_SRC
            ${OD_PLATFORM_SRC}
            od/platform/QtApplication.cpp
            od/platform/QtApplication.hpp
            od/platform/GLQtWindow.cpp
            od/platform/GLQtWindow.hpp
            od/platform/ODQGLWidget.cpp
            od/platform/ODQGLWidget.hpp
            )

        set(OD_PLATFORM_LIBRARIES
            ${OD_PLATFORM_LIBRARIES}
            ${QT_LIBRARIES}
            )
    endif(QT4_FOUND)

endif(OPENGL_FOUND)

# TODO: Possibly add GLFW support
# (Link against GLFW if found)
if(GLFW_FOUND)
    #SET(OD_GRAPHICS_LIBRARIES
    #    ${OD_GRAPHICS_LIBRARIES}
    #    ${GLFW_LIBRARIES}
    #)
endif()


add_library(od_platform SHARED ${OD_PLATFORM_SRC})
target_link_libraries(od_platform ${OD_PLATFORM_LIBRARIES})

# Module: Graphics
#

# Base source files for graphics module
set(OD_GRAPHICS_SRC
    od/graphics/hal/Device.cpp
    od/graphics/hal/Device.hpp
    od/graphics/hal/DeviceType.hpp
    od/graphics/hal/DeviceFactory.cpp
    od/graphics/hal/DeviceFactory.hpp
    od/graphics/hal/DeviceResource.cpp
    od/graphics/hal/DeviceResource.hpp
    od/graphics/hal/DeviceResourceManager.cpp
    od/graphics/hal/DeviceResourceManager.hpp
    od/graphics/hal/Context.cpp
    od/graphics/hal/Context.hpp
    od/graphics/hal/Texture.cpp
    od/graphics/hal/Texture.hpp
    od/graphics/hal/VertexBuffer.cpp
    od/graphics/hal/VertexBuffer.hpp
    od/graphics/hal/Shader.cpp
    od/graphics/hal/Shader.hpp
    od/graphics/hal/VertexShader.cpp
    od/graphics/hal/VertexShader.hpp
    od/graphics/hal/TessellationControlShader.cpp
    od/graphics/hal/TessellationControlShader.hpp
    od/graphics/hal/TessellationEvaluationShader.cpp
    od/graphics/hal/TessellationEvaluationShader.hpp
    od/graphics/hal/GeometryShader.cpp
    od/graphics/hal/GeometryShader.hpp
    od/graphics/hal/FragmentShader.cpp
    od/graphics/hal/FragmentShader.hpp
    od/graphics/hal/ShaderProgram.cpp
    od/graphics/hal/ShaderProgram.hpp
    )
set(OD_GRAPHICS_LIBRARIES "" )

# OpenGL support for graphics module.
# Included only if OpenGL present.
if(OPENGL_FOUND)
    set(OD_GRAPHICS_SRC
        ${OD_GRAPHICS_SRC}
        od/graphics/hal/gl/OpenGL.hpp
        od/graphics/hal/gl/GLVersion.hpp
        od/graphics/hal/gl/GLDevice.cpp
        od/graphics/hal/gl/GLDevice.hpp
        od/graphics/hal/gl/GLContext.cpp
        od/graphics/hal/gl/GLContext.hpp
        od/graphics/hal/gl/GLTexture.cpp
        od/graphics/hal/gl/GLTexture.hpp
        od/graphics/hal/gl/GLFragmentShader.cpp
        od/graphics/hal/gl/GLFragmentShader.hpp
        od/graphics/hal/gl/GLGeometryShader.cpp
        od/graphics/hal/gl/GLGeometryShader.hpp
        od/graphics/hal/gl/GLShaderProgram.cpp
        od/graphics/hal/gl/GLShaderProgram.hpp
        od/graphics/hal/gl/GLTessellationControlShader.cpp
        od/graphics/hal/gl/GLTessellationControlShader.hpp
        od/graphics/hal/gl/GLTessellationEvaluationShader.cpp
        od/graphics/hal/gl/GLTessellationEvaluationShader.hpp
        od/graphics/hal/gl/GLVertexBuffer.cpp
        od/graphics/hal/gl/GLVertexBuffer.hpp
        od/graphics/hal/gl/GLVertexShader.cpp
        od/graphics/hal/gl/GLVertexShader.hpp
        )

        set(OD_GRAPHICS_LIBRARIES
            ${OD_GRAPHICS_LIBRARIES}
            ${OPENGL_LIBRARIES}
        )

endif(OPENGL_FOUND)

# On OS X, link against Cocoa and IOKit frameworks
if(APPLE)
    SET(OD_GRAPHICS_LIBRARIES
        ${OD_GRAPHICS_LIBRARIES}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
    )
endif()

# Link against GLEW if found
if(GLEW_FOUND)
    SET(OD_GRAPHICS_LIBRARIES
        ${OD_GRAPHICS_LIBRARIES}
        ${GLEW_LIBRARIES})
endif()

# OD Graphics library
add_library(od_graphics SHARED ${OD_GRAPHICS_SRC})
target_link_libraries(od_graphics ${OD_GRAPHICS_LIBRARIES})

