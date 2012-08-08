#include "GLQtWindow.hpp"
#include "../graphics/hal/DeviceFactory.hpp"

namespace od {
namespace platform {

GLQtWindow::GLQtWindow(QWidget* parent) :
    GLWindow(),
    mWidget(0),
    mDevice(0)
{
    // Allocate QGLWidget
    mWidget = new QGLWidget(parent);
    mWidget->show();
}

GLQtWindow::~GLQtWindow()
{
    // Free device if allocated
    if(mDevice != 0)
    {
        delete mDevice;
        mDevice = 0;
    }

    // Free allocated widget
    delete mWidget;
    mWidget = 0;
}

QWidget* GLQtWindow::getWidget()
{
    // Return pointer to QGLWidget
    return mWidget;
}

od::graphics::hal::Device* GLQtWindow::createDevice()
{
    //mDevice = new od::graphics::hal::gl::GLDevice();

    // Create new OpenGL device
    mDevice = dynamic_cast <od::graphics::hal::gl::GLDevice*>
            (od::graphics::hal::DeviceFactory::createDevice(
                 od::graphics::hal::DEVICETYPE_OPENGL4));
    return mDevice;
}

void GLQtWindow::setDevice(od::graphics::hal::Device *device)
{
    mDevice = dynamic_cast <od::graphics::hal::gl::GLDevice*> (device);
}

od::graphics::hal::Device* GLQtWindow::getDevice()
{
    return mDevice;
}

void GLQtWindow::onResize(ODuint16 width, ODuint16 height)
{
}

}
}
