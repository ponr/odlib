#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

Shader::Shader() :
    DeviceResource(),
    mShaderSource(),
    mCompilationError()
{
}

Shader::~Shader()
{
}

void Shader::setSource(std::string src)
{
    unload();
    mShaderSource = src;
}

}
}
}
