/// GL Context class

#ifndef OD_GRAPHICS_HAL_GL_GLCONTEXT_HPP
#define OD_GRAPHICS_HAL_GL_GLCONTEXT_HPP

#include "../Context.hpp"
#include "GLVersion.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL Context class
class GLContext : public od::graphics::hal::Context
{
public:
    GLContext();
    virtual ~GLContext();

private:
    GLVersion mGLVersion;
    bool mInitialized;
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLCONTEXT_HPP */
