/// Geometry Shader base class

#ifndef OD_GRAPHICS_HAL_GEOMETRYSHADER_HPP
#define OD_GRAPHICS_HAL_GEOMETRYSHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Geometry Shader base class
class GeometryShader : public Shader
{
public:
    /// Destructor
    virtual ~GeometryShader();

protected:
    GeometryShader();

private:
    GeometryShader(const GeometryShader&);
    GeometryShader& operator= (const GeometryShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_GEOMETRYSHADER_HPP */
