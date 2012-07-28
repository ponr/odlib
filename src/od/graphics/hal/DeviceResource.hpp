/// Device resource base class

#ifndef OD_GRAPHICS_HAL_DEVICERESOURCE_HPP
#define OD_GRAPHICS_HAL_DEVICERESOURCE_HPP

#include "../../core/types.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Device resource base class.
class DeviceResource
{
public:
    /// Destructor
    virtual ~DeviceResource();

    /// Unload resource from graphics memory.
    /// Derived classes should implement this.
    virtual void unload() = 0;

    /// Sets resource state invalid. Doesn't do any cleaning.
    /// Used by DeviceResourceManager to mark resource invalid
    /// for example in cases of context loss.
    void invalidate();

    /// Tells if resource is valid to use.
    /// @returns Boolean which tells if resource is valid to use.
    bool isValid() const;

    /// Returns size in bytes if resource has reasonable size to tell.
    /// Returns 0 if unimplemented by derived class or no reasonable size.
    ODuint32 getSize() const;

protected:
    DeviceResource();
    virtual void invalidated();

    /// Sets boolean flag to tell if resource is valid to use.
    /// Derived classes should set this to true when resource
    /// is properly loaded.
    void setValidness(bool validness);

private:
    DeviceResource(const DeviceResource&);
    DeviceResource& operator= (const DeviceResource&);

    // Variable to hold information about validness
    bool mValidness;
};

}
}
}

#endif /* OD_GRAPHICS_HAL_DEVICERESOURCE_HPP */
