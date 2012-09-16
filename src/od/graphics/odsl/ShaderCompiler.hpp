/// ShaderCompiler base class

#ifndef OD_GRAPHICS_ODSL_SHADERCOMPILER_HPP
#define OD_GRAPHICS_ODSL_SHADERCOMPILER_HPP

#include <string>

namespace od {
namespace graphics {
namespace odsl {

/// ShaderCompiler base class.
/// Compiles ODSL shader to desired shading language.
class ShaderCompiler
{
public:
    /// Constructor
    explicit ShaderCompiler();

    /// Destructor
    virtual ~ShaderCompiler();

    /// Sets shader source code (ODSL).
    /// @param src Source code
    void setSource(const std::string& src);

    /// Compiles shader. Returns true or false depending on success.
    /// On failure, get compilation error using getCompilationError();
    /// @return true if compilation is successful, false if not.
    bool compile();

    /// Returns compilation error in string.
    /// @return String containing compilaton error.
    std::string getCompilationError() const;

private:
    ShaderCompiler(const ShaderCompiler&);
    ShaderCompiler& operator= (const ShaderCompiler&);

    // Contains shader source after setting. Can be cleared after compilation.
    std::string mSource;

    // Set true when compilation is succesful
    bool mCompilationSuccess;

    // Constains possible compilation error
    std::string mCompilationError;

};

}
}
}

#endif /* OD_GRAPHICS_ODSL_SHADERCOMPILER_HPP */
