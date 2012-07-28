/// GL Device class

#ifndef OD_GRAPHICS_HAL_GL_GLDEVICE_HPP
#define OD_GRAPHICS_HAL_GL_GLDEVICE_HPP

#include "../Device.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL Device class
class GLDevice : public od::graphics::hal::Device
{
public:
    GLDevice();
    virtual ~GLDevice();

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLDEVICE_HPP */
