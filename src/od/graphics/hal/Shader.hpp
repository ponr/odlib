/// Shader base class

#ifndef OD_GRAPHICS_HAL_SHADER_HPP
#define OD_GRAPHICS_HAL_SHADER_HPP

#include "DeviceResource.hpp"
#include <string>

namespace od {
namespace graphics {
namespace hal {

/// Shader base class
class Shader : public DeviceResource
{
public:
    /// Destructor
    virtual ~Shader();

    /// Sets shader source code (ODSL). Invalidates/Unloads present shader.
    /// @param src Source code
    void setSource(std::string src);

    /// Compiles shader. Returns true or false depending on success.
    /// On failure, get compilation error using getCompilationError();
    /// @return true if compilation is successful, false if not.
    virtual bool compile() = 0;

    /// Returns compilation error in string.
    /// @return String containing compilaton error.
    std::string getCompilationError() const;

protected:
    Shader();

    // Contains shader source after setting. Can be cleared after compilation.
    std::string mShaderSource;

    // Constains possible compilation error
    std::string mCompilationError;

private:
    Shader(const Shader&);
    Shader& operator= (const Shader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_SHADER_HPP */
