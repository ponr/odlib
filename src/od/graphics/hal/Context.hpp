/// Context base class

#ifndef OD_GRAPHICS_HAL_CONTEXT_HPP
#define OD_GRAPHICS_HAL_CONTEXT_HPP

#include "DeviceResource.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Context base class.
/// Class which handles all rendering related states.
class Context : public DeviceResource
{
public:
    /// Destructor
    virtual ~Context();

protected:
    Context();

private:
    Context(const Context&);
    Context& operator= (const Context&);
};

}
}
}

#endif /* OD_GRAPHICS_HAL_CONTEXT_HPP */
