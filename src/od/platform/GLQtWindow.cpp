#include "GLQtWindow.hpp"
#include "ODQGLWidget.hpp"
#include "../graphics/hal/DeviceFactory.hpp"

#include <QtOpenGL/QGLFormat>
#include <QSize>

namespace od {
namespace platform {

GLQtWindow::GLQtWindow(QWidget* parent) :
    GLWindow(),
    mWidget(0),
    mDevice(0)
{
    // Setting vsync on
    QGLFormat format;
    format.setSwapInterval(1);

    // TODO: Examine more, if this variable is initialized before
    //       QGLFormat above, following widget creation causes segfault.
    QSize size(128,100);

    // Creating new ODQGLWidget
    mWidget = new ODQGLWidget(size, format, "ODQGLWidget", parent);
    mWidget->show();
}

GLQtWindow::~GLQtWindow()
{
    // Free allocated widget
    delete mWidget;
    mWidget = 0;
}

QWidget* GLQtWindow::getWidget()
{
    // Return pointer to QGLWidget
    return mWidget;
}

std::shared_ptr <od::graphics::hal::Device> GLQtWindow::createDevice()
{
    // Create new OpenGL device
    mDevice = od::graphics::hal::DeviceFactory::createDevice(
                 od::graphics::hal::DEVICETYPE_OPENGL4);
    return std::shared_ptr <od::graphics::hal::Device> (mDevice);
}

void GLQtWindow::setDevice(std::shared_ptr <od::graphics::hal::Device> device)
{
    mDevice = device;
}

std::shared_ptr <od::graphics::hal::Device> GLQtWindow::getDevice()
{
    return mDevice;
}

void GLQtWindow::onResize(ODuint16 width, ODuint16 height)
{
}

}
}
