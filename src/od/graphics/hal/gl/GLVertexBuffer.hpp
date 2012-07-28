/// GL VertexBuffer Object class

#ifndef OD_GRAPHICS_HAL_GL_GLVERTEXBUFFER_HPP
#define OD_GRAPHICS_HAL_GL_GLVERTEXBUFFER_HPP

#include "../VertexBuffer.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL VertexBuffer Object class
class GLVertexBuffer : public od::graphics::hal::VertexBuffer
{
public:
    GLVertexBuffer();
    virtual ~GLVertexBuffer();

    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLVERTEXBUFFER_HPP */
