#include <cstdlib>
#include <od/graphics/hal/DeviceFactory.hpp>
#include <od/graphics/hal/Device.hpp>
#include <od/graphics/hal/Window.hpp>

using od::graphics::hal::DeviceFactory;
using od::graphics::hal::Device;
using od::graphics::hal::Window;

int main()
{
    Device* device = DeviceFactory::createDevice();

    Window* window = device->createWindow();

    return EXIT_SUCCESS;
}
