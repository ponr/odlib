#include "GLComputeShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLComputeShader::GLComputeShader() :
    od::graphics::hal::ComputeShader()
{
}

GLComputeShader::~GLComputeShader()
{
}

bool GLComputeShader::compile()
{
    return false;
}

void GLComputeShader::unload()
{
}

}
}
}
}

