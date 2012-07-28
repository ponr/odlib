/// Device Factory

#ifndef OD_GRAPHICS_HAL_DEVICEFACTORY_HPP
#define OD_GRAPHICS_HAL_DEVICEFACTORY_HPP

#include "DeviceType.hpp"

namespace od {
namespace graphics {
namespace hal {

class Device;

/// Device Factory.
/// Used to create device.
class DeviceFactory
{
public:
    /// Tries to create device of desired type. Tries to fallback if fails.
    /// @returns Pointer to created device. Return null if fails.
    static Device* createDevice(
        const DeviceType &desiredtype = DEVICETYPE_DEFAULT);
private:
    DeviceFactory();
    virtual ~DeviceFactory();
    DeviceFactory(const DeviceFactory&);
    DeviceFactory& operator= (const DeviceFactory&);
};

}
}
}

#endif /* OD_GRAPHICS_HAL_DEVICEFACTORY_HPP */
