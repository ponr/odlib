#include <cstdlib>
#include <od/platform/Application.hpp>
#include <od/platform/ApplicationFactory.hpp>
#include <od/platform/Window.hpp>
#include <od/graphics/hal/DeviceFactory.hpp>
#include <od/graphics/hal/Device.hpp>
#include <QApplication>

using od::platform::Application;
using od::platform::ApplicationFactory;
using od::platform::Window;
using od::graphics::hal::DeviceFactory;
using od::graphics::hal::Device;

int main(int argc, char** argv)
{
    // Initializing Application Platform
    Application* app =
            ApplicationFactory::createApplication(argc, argv);

    Window* window = app->createWindow();

    // Create new ODlib HAL Device
    Device* device = DeviceFactory::createDevice(
                od::graphics::hal::DEVICETYPE_OPENGLES2);

    // If HAL Device could not be created, exit
    if(!device)
    {
        return EXIT_FAILURE;
    }

    delete device;
    //delete window;

    return EXIT_SUCCESS;
}
