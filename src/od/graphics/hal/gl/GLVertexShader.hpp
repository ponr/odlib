/// GL VertexShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLVERTEXSHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLVERTEXSHADER_HPP

#include "../VertexShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL VertexShader Object class
class GLVertexShader : public od::graphics::hal::VertexShader
{
public:
    GLVertexShader();
    virtual ~GLVertexShader();

    bool compile();
    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLVERTEXSHADER_HPP */
