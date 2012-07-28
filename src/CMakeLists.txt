
set(OD_CORE_SRC
    od/core/types.hpp
    )

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
    od/graphics/hal/Texture.cpp
    od/graphics/hal/Texture.hpp
    od/graphics/hal/Context.cpp
    od/graphics/hal/Context.hpp
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

#add_library(od_core ${OD_CORE_SRC})
add_library(od_graphics ${OD_GRAPHICS_SRC})

