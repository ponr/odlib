#include "GLFragmentShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLFragmentShader::GLFragmentShader() :
    od::graphics::hal::FragmentShader()
{
}

GLFragmentShader::~GLFragmentShader()
{
}

bool GLFragmentShader::compile()
{
    return false;
}

void GLFragmentShader::unload()
{
}

}
}
}
}

