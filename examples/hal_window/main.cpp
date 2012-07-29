#include <cstdlib>
#include <od/graphics/hal/DeviceFactory.hpp>
#include <od/graphics/hal/Device.hpp>

using od::graphics::hal::DeviceFactory;
using od::graphics::hal::Device;

int main()
{
    Device* device = DeviceFactory::createDevice();
    return EXIT_SUCCESS;
}
