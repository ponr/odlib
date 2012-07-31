#include <cstdlib>
#include <od/graphics/hal/DeviceFactory.hpp>
#include <od/graphics/hal/Device.hpp>
#include <od/graphics/hal/Window.hpp>
#include <od/graphics/hal/gl/GLQtWindow.hpp>
#include <QApplication>

using od::graphics::hal::DeviceFactory;
using od::graphics::hal::Device;
using od::graphics::hal::Window;
using od::graphics::hal::gl::GLQtWindow;

int main(int argc, char** argv)
{
    // Initializing Qt Application
    QApplication app(argc, argv);

    // Create new ODlib HAL Device
    Device* device = DeviceFactory::createDevice(
                od::graphics::hal::DEVICETYPE_OPENGLES2);

    // If HAL Device could not be created, exit
    if(!device)
    {
        return EXIT_FAILURE;
    }

    // Create new GL Qt Window
    GLQtWindow* window = new GLQtWindow();

    // If window can't be set, exit
    if(!device->setWindow(window))
    {
        delete device;
        delete window;

        return EXIT_FAILURE;
    }

    app.exec();

    delete device;
    delete window;

    return EXIT_SUCCESS;
}
