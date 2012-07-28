/// Fragment Shader base class

#ifndef OD_GRAPHICS_HAL_FRAGMENTSHADER_HPP
#define OD_GRAPHICS_HAL_FRAGMENTSHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// Fragment Shader base class
class FragmentShader : public Shader
{
public:
    /// Destructor
    virtual ~FragmentShader();

protected:
    FragmentShader();

private:
    FragmentShader(const FragmentShader&);
    FragmentShader& operator= (const FragmentShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_FRAGMENTSHADER_HPP */
