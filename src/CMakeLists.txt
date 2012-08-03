# Module: Core
# Source files for core module
set(OD_CORE_SRC
    od/core/types.hpp
    )

#add_library(od_core SHARED ${OD_CORE_SRC})

# Module: Platform
# Source files for platform module
set(OD_PLATFORM_SRC
    od/platform/Application.cpp
    od/platform/Application.hpp
    )

add_library(od_platform SHARED ${OD_PLATFORM_SRC})

# Module: Graphics
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
    od/graphics/hal/Window.cpp
    od/graphics/hal/Window.hpp
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

# OpenGL support for graphics module.
# Included only if OpenGL present.
if(OPENGL_FOUND)
    set(OD_GRAPHICS_SRC
        ${OD_GRAPHICS_SRC}
        od/graphics/hal/gl/OpenGL.hpp
        od/graphics/hal/gl/GLVersion.hpp
        od/graphics/hal/gl/GLDevice.cpp
        od/graphics/hal/gl/GLDevice.hpp
        od/graphics/hal/gl/GLWindow.cpp
        od/graphics/hal/gl/GLWindow.hpp
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

    # Qt4 widget support for HAL GL
    if(QT4_FOUND)
        SET(OD_GRAPHICS_SRC
            ${OD_GRAPHICS_SRC}
            od/graphics/hal/gl/GLQtWindow.cpp
            od/graphics/hal/gl/GLQtWindow.hpp
            )
    endif(QT4_FOUND)

endif(OPENGL_FOUND)

SET(OD_GRAPHICS_LIBRARIES "" )

# Link against OpenGL libraries if present
if(OPENGL_FOUND)
    SET(OD_GRAPHICS_LIBRARIES
        ${OD_GRAPHICS_LIBRARIES}
        ${OPENGL_LIBRARIES}
    )

    # Link against Qt4
    if(QT4_FOUND)
        SET(OD_GRAPHICS_LIBRARIES
            ${OD_GRAPHICS_LIBRARIES}
            ${QT_LIBRARIES}
            )
    endif(QT4_FOUND)

endif(OPENGL_FOUND)

# On OS X, link against Cocoa and IOKit frameworks
if(APPLE)
    SET(OD_GRAPHICS_LIBRARIES
        ${OD_GRAPHICS_LIBRARIES}
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
    )
endif()

# Link against GLFW if found
if(GLFW_FOUND)
    SET(OD_GRAPHICS_LIBRARIES
        ${OD_GRAPHICS_LIBRARIES}
        ${GLFW_LIBRARIES}
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

