/// Device resource manager

#ifndef OD_GRAPHICS_HAL_DEVICERESOURCEMANAGER_HPP
#define OD_GRAPHICS_HAL_DEVICERESOURCEMANAGER_HPP

namespace od {
namespace graphics {
namespace hal {

class DeviceResourceManager
{
public:
    DeviceResourceManager();
    virtual ~DeviceResourceManager();
private:
    DeviceResourceManager(const DeviceResourceManager&);
    DeviceResourceManager& operator= (const DeviceResourceManager&);
};

}
}
}

#endif /* OD_GRAPHICS_HAL_DEVICERESOURCEMANAGER_HPP */
