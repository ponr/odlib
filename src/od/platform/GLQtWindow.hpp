/// Implements Qt Widget for odlib OpenGL

#ifndef OD_PLATFORM_GLQTWINDOW_HPP
#define OD_PLATFORM_GLQTWINDOW_HPP

#include "GLWindow.hpp"
#include "../graphics/hal/gl/GLDevice.hpp"

#include <QWidget>

namespace od {
namespace platform {

class ODQGLWidget;

/// Implements Qt Widget for odlib OpenGL
class GLQtWindow : public GLWindow
{
public:
    GLQtWindow(QWidget* parent = 0);
    virtual ~GLQtWindow();

    QWidget* getWidget();

    /// Create Device for Window
    /// @return Pointer to Device
    od::graphics::hal::Device* createDevice();

    /// Set Device for Window
    /// @param device Pointer to Device
    void setDevice(od::graphics::hal::Device* device);

    /// Get Device of Window
    /// @return Pointer to Device
    od::graphics::hal::Device* getDevice();


protected:
    void onResize(ODuint16 width, ODuint16 height);

private:
    GLQtWindow(const GLQtWindow&);
    GLQtWindow& operator= (const GLQtWindow&);

    // Qt widget for GL
    ODQGLWidget* mWidget;

    // HAL GLDevice pointer
    od::graphics::hal::gl::GLDevice* mDevice;
};

}
}

#endif /* OD_PLATFORM_GLQTWINDOW_HPP */
