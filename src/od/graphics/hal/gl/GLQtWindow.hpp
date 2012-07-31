/// Implements Qt Widget for odlib OpenGL

#ifndef OD_GRAPHICS_HAL_GL_GLQTWINDOW_HPP
#define OD_GRAPHICS_HAL_GL_GLQTWINDOW_HPP

#include "GLWindow.hpp"
#include <QtOpenGL/QGLWidget>

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// Implements Qt Widget for odlib OpenGL
class GLQtWindow : public GLWindow
{
public:
    GLQtWindow(QWidget* parent = 0);
    virtual ~GLQtWindow();

    QWidget* getWidget();

protected:
    void onResize(ODuint16 width, ODuint16 height);

private:
    GLQtWindow(const GLQtWindow&);
    GLQtWindow& operator= (const GLQtWindow&);

    QGLWidget* mWidget;
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLQTWINDOW_HPP */
