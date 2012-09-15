/// GL ComputeShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLCOMPUTESHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLCOMPUTESHADER_HPP

#include "../ComputeShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL ComputeShader Object class
class GLComputeShader : public od::graphics::hal::ComputeShader
{
public:
    GLComputeShader();
    virtual ~GLComputeShader();

    bool compile();
    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLCOMPUTESHADER_HPP */
