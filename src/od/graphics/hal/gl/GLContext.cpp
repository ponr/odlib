#include "GLContext.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLContext::GLContext() :
    od::graphics::hal::Context(),
    mGLVersion(GLVERSION_GL4),
    mInitialized(false)
{
}

GLContext::~GLContext()
{
}

void GLContext::unload()
{
    // TODO: Unload code
}

}
}
}
}

