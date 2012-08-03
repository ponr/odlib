#include "GLQtWindow.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLQtWindow::GLQtWindow(QWidget* parent) :
    GLWindow(),
    mWidget(0)
{
    mWidget = new QGLWidget(parent);
    mWidget->show();
}

GLQtWindow::~GLQtWindow()
{
    delete mWidget;
}

QWidget* GLQtWindow::getWidget()
{
    return mWidget;
}

void GLQtWindow::onResize(ODuint16 width, ODuint16 height)
{
}

}
}
}
}

