/// GL FragmentShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLFRAGMENTSHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLFRAGMENTSHADER_HPP

#include "../FragmentShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL FragmentShader Object class
class GLFragmentShader : public od::graphics::hal::FragmentShader
{
public:
    GLFragmentShader();
    virtual ~GLFragmentShader();

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLFRAGMENTSHADER_HPP */
