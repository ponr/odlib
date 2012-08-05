#include "GLVertexShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLVertexShader::GLVertexShader() :
    od::graphics::hal::VertexShader()
{
}

GLVertexShader::~GLVertexShader()
{
}

bool GLVertexShader::compile()
{
    return false;
}

void GLVertexShader::unload()
{
}

}
}
}
}

