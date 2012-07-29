/// Window base class

#ifndef OD_GRAPHICS_HAL_WINDOW
#define OD_GRAPHICS_HAL_WINDOW

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

private:
    Window(const Window&);
    Window& operator= (const Window&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_WINDOW */
