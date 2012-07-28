/// Vertex Shader base class

#ifndef OD_GRAPHICS_HAL_VERTEXSHADER_HPP
#define OD_GRAPHICS_HAL_VERTEXSHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Base class for Vertex Shader
class VertexShader : public Shader
{
public:
    /// Destructor
    virtual ~VertexShader();

protected:
    VertexShader();

private:
    VertexShader(const VertexShader&);
    VertexShader& operator= (const VertexShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_VERTEXSHADER_HPP */
