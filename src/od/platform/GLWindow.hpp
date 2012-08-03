#ifndef OD_GRAPHICS_HAL_GL_GLWINDOW_HPP
#define OD_GRAPHICS_HAL_GL_GLWINDOW_HPP

#include "../Window.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

class GLWindow : public od::graphics::hal::Window
{
public:
    /// Destructor
    virtual ~GLWindow();

protected:
    GLWindow();

private:
    GLWindow(const Window&);
    GLWindow& operator= (const Window&);

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLWINDOW_HPP */
