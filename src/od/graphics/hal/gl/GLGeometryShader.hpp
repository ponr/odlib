/// GL GeometryShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLGEOMETRYSHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLGEOMETRYSHADER_HPP

#include "../GeometryShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL GeometryShader Object class
class GLGeometryShader : public od::graphics::hal::GeometryShader
{
public:
    GLGeometryShader();
    virtual ~GLGeometryShader();

    bool compile();
    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLGEOMETRYSHADER_HPP */
