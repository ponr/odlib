/// GL ShaderProgram Object class

#ifndef OD_GRAPHICS_HAL_GL_GLSHADERPROGRAM_HPP
#define OD_GRAPHICS_HAL_GL_GLSHADERPROGRAM_HPP

#include "../ShaderProgram.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL ShaderProgram Object class
class GLShaderProgram : public od::graphics::hal::ShaderProgram
{
public:
    GLShaderProgram();
    virtual ~GLShaderProgram();

    void unload();
    void addShader(Shader *shader);

private:
    GLShaderProgram(const GLShaderProgram&);
    GLShaderProgram& operator= (const GLShaderProgram&);
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLSHADERPROGRAM_HPP */
