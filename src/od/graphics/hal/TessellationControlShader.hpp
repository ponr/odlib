/// TessellationControl Shader base class

#ifndef OD_GRAPHICS_HAL_TESSELLATIONCONTROLSHADER_HPP
#define OD_GRAPHICS_HAL_TESSELLATIONCONTROLSHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// TessellationControl Shader base class
class TessellationControlShader : public Shader
{
public:
    /// Destructor
    virtual ~TessellationControlShader();

protected:
    TessellationControlShader();

private:
    TessellationControlShader(const TessellationControlShader&);
    TessellationControlShader& operator= (const TessellationControlShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_TESSELLATIONCONTROLSHADER_HPP */
