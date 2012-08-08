#include <cstdlib>
#include <od/platform/Application.hpp>
#include <od/platform/ApplicationFactory.hpp>
#include <od/platform/Window.hpp>
#include <od/graphics/hal/Device.hpp>
#include <QApplication>

using od::platform::Application;
using od::platform::ApplicationFactory;
using od::platform::Window;
using od::graphics::hal::Device;

int main(int argc, char** argv)
{
    // Initializing Application Platform
    Application* app =
            ApplicationFactory::createApplication(argc, argv);

    // Create window using application object
    Window* window = app->createWindow();

    // Create new HAL Device
    Device* device = window->createDevice();

    // If HAL Device could not be created, exit
    if(!device)
    {
        return EXIT_FAILURE;
    }

    delete device;
    delete window;
    delete app;

    return EXIT_SUCCESS;
}
