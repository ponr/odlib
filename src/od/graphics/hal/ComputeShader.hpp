/// Fragment Shader base class

#ifndef OD_GRAPHICS_HAL_COMPUTESHADER_HPP
#define OD_GRAPHICS_HAL_COMPUTESHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Fragment Shader base class
class ComputeShader : public Shader
{
public:
    /// Destructor
    virtual ~ComputeShader();

protected:
    ComputeShader();

private:
    ComputeShader(const ComputeShader&);
    ComputeShader& operator= (const ComputeShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_COMPUTESHADER_HPP */
