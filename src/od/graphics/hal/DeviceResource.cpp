#include "DeviceResource.hpp"

namespace od {
namespace graphics {
namespace hal {

DeviceResource::DeviceResource() :
    mValidness(false)
{
}

DeviceResource::~DeviceResource()
{
}

void DeviceResource::invalidate()
{
    mValidness = false;
    invalidated();
}

bool DeviceResource::isValid() const
{
    return mValidness;
}

ODuint32 DeviceResource::getSize() const
{
    // When unimplemented by derived class, return 0
    return 0;
}

void DeviceResource::invalidated()
{
}

void DeviceResource::setValidness(bool validness)
{
    mValidness = validness;
}

}
}
}
