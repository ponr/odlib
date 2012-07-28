/// GL TessellationControlShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLTESSELLATIONCONTROLSHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLTESSELLATIONCONTROLSHADER_HPP

#include "../TessellationControlShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL TessellationControlShader Object class
class GLTessellationControlShader :
    public od::graphics::hal::TessellationControlShader
{
public:
    GLTessellationControlShader();
    virtual ~GLTessellationControlShader();

    bool compile();
    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLTESSELLATIONCONTROLSHADER_HPP */
