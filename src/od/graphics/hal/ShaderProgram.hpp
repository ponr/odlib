/// Shader Program base class

#ifndef OD_GRAPHICS_HAL_SHADERPROGRAM_HPP
#define OD_GRAPHICS_HAL_SHADERPROGRAM_HPP

#include "DeviceResource.hpp"

namespace od {
namespace graphics {
namespace hal {

class Shader;

/// Shader Program base class.
class ShaderProgram : public DeviceResource
{
public:
    /// Destructor
    virtual ~ShaderProgram();

    virtual void addShader(Shader* shader) = 0;

protected:
    ShaderProgram();

private:
    ShaderProgram(const ShaderProgram&);
    ShaderProgram& operator= (const ShaderProgram&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_SHADERPROGRAM_HPP */
