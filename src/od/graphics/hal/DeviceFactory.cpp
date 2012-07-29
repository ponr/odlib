#include "DeviceFactory.hpp"

#ifdef OPENGL
#include "gl/GLDevice.hpp"
#endif /* OPENGL */

#ifdef WIN32
// TODO: Include D3D device header
#endif

// TODO: Include OpenGL device header

namespace od {
namespace graphics {
namespace hal {

Device* DeviceFactory::createDevice(const DeviceType& desiredtype)
{
    DeviceType type = desiredtype;

    if(type == DEVICETYPE_DEFAULT)
    {
#ifdef WIN32
        type = DEVICETYPE_DIRECT3D11;
#elif ANDROID
        type = DEVICETYPE_OPENGLES2;
#else
        type = DEVICETYPE_OPENGL4;
#endif
    }

    // TODO: Actual device creation

    // If Direct3D 11
    if(type == DEVICETYPE_DIRECT3D11)
    {
#ifdef WIN32
        // TODO: Create Direct3D 11 Device
#else
        type = DEVICETYPE_OPENGL4;
#endif
    }

    // TODO: Check OpenGL version capabilities.

    if(type == DEVICETYPE_OPENGL4)
    {
    }

    if(type == DEVICETYPE_OPENGL3)
    {
    }

    if(type == DEVICETYPE_OPENGLES2)
    {
    }

    return new gl::GLDevice();
}

}
}
}
