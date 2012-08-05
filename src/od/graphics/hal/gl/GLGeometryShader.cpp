#include "GLGeometryShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLGeometryShader::GLGeometryShader() :
    od::graphics::hal::GeometryShader()
{
}

GLGeometryShader::~GLGeometryShader()
{
}

bool GLGeometryShader::compile()
{
    return false;
}

void GLGeometryShader::unload()
{
}

}
}
}
}

