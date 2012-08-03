#ifndef OD_PLATFORM_GLWINDOW_HPP
#define OD_PLATFORM_GLWINDOW_HPP

#include "Window.hpp"

namespace od {
namespace platform {

class GLWindow : public Window
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

#endif /* OD_PLATFORM_GLWINDOW_HPP */
