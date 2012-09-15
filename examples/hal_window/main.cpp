#include <cstdlib>
#include <od/platform/Application.hpp>
#include <od/platform/ApplicationFactory.hpp>
#include <od/platform/Window.hpp>
#include <od/graphics/hal/Device.hpp>
#include <od/graphics/hal/Context.hpp>
#include <QApplication>
#include <memory>

using od::platform::Application;
using od::platform::ApplicationFactory;
using od::platform::Window;
using od::graphics::hal::Device;
using od::graphics::hal::Context;

int main(int argc, char** argv)
{
    // Initializing Application Platform
    std::shared_ptr <Application> app =
            ApplicationFactory::createApplication(argc, argv);

    // Create window using application object
    std::shared_ptr <Window> window = app->createWindow();

    // Create new HAL rendering device
    std::shared_ptr <Device> device = window->createDevice();

    // If HAL Device could not be created, exit
    if(!device)
    {
        return EXIT_FAILURE;
    }

    // Create rendering context using device
    std::shared_ptr <Context> context = device->createContext();

    return EXIT_SUCCESS;
}
