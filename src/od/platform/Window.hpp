/// Window base class

#ifndef OD_PLATFORM_WINDOW_HPP
#define OD_PLATFORM_WINDOW_HPP

#include "../core/types.hpp"
#include <memory>

namespace od {

namespace graphics {
namespace hal {

class Device;

}
}

namespace platform {

/// Window base class.
/// Window-class handles creation of Window or Widget that contains
/// drawing area for specific graphics API used.
class Window
{
public:
    /// Destructor
    virtual ~Window();

    /// Create Device for Window
    /// @return Pointer to Device
    virtual std::shared_ptr <od::graphics::hal::Device> createDevice() = 0;

    /// Set Device for Window
    /// @param device Pointer to Device
    virtual void setDevice(
            std::shared_ptr <od::graphics::hal::Device> device) = 0;

    /// Get Device of Window
    /// @return Pointer to Device
    virtual std::shared_ptr <od::graphics::hal::Device> getDevice() = 0;

protected:
    Window();

    /// Function which will be called on resize
    virtual void onResize(ODuint16 width, ODuint16 height) = 0;

private:
    Window(const Window&);
    Window& operator= (const Window&);

};

}
}

#endif /* OD_PLATFORM_WINDOW_HPP */
