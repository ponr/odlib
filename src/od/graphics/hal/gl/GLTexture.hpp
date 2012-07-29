/// GL Texture Object class

#ifndef OD_GRAPHICS_HAL_GL_GLTEXTURE_HPP
#define OD_GRAPHICS_HAL_GL_GLTEXTURE_HPP

#include "../Texture.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL Texture Object class
class GLTexture : public od::graphics::hal::Texture
{
public:
    GLTexture();
    virtual ~GLTexture();

    void unload();
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLTEXTURE_HPP */
