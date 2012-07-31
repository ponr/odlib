/// Window base class

#ifndef OD_GRAPHICS_HAL_WINDOW_HPP
#define OD_GRAPHICS_HAL_WINDOW_HPP

#include "../../core/types.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Window base class.
/// Window-class handles creation of Window or Widget that contains
/// drawing area for specific graphics API used.
class Window
{
public:
    /// Destructor
    virtual ~Window();

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
}

#endif /* OD_GRAPHICS_HAL_WINDOW_HPP */
