/// Vertex Buffer Object base class

#ifndef OD_GRAPHICS_HAL_VERTEXBUFFER_HPP
#define OD_GRAPHICS_HAL_VERTEXBUFFER_HPP

#include "DeviceResource.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Vertex Buffer Object base class.
class VertexBuffer : public DeviceResource
{
public:
    /// Destructor
    virtual ~VertexBuffer();

    /// TODO: Define functions for setting vertex
    ///       buffer contents

protected:
    VertexBuffer();

private:
    VertexBuffer(const VertexBuffer&);
    VertexBuffer& operator= (const VertexBuffer&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_VERTEXBUFFER_HPP */
