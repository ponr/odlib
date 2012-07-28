/// GL Device class

#ifndef OD_GRAPHICS_HAL_GL_GLDEVICE_HPP
#define OD_GRAPHICS_HAL_GL_GLDEVICE_HPP

#include "../Device.hpp"
#include "../DeviceFactory.hpp"
#include "../DeviceResourceManager.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL Device class
class GLDevice : public od::graphics::hal::Device
{
    friend class od::graphics::hal::DeviceFactory;

public:

    virtual ~GLDevice();
    // Resource creation

    /// Create context.
    /// @return Pointer to context.
    virtual Context* createContext();

    /// Create texture.
    /// @return Pointer to texture.
    virtual Texture* createTexture();

    /// Create vertex buffer.
    /// @return Pointer to vertex buffer.
    virtual VertexBuffer* createVertexBuffer();

    /// Create vertex shader.
    /// @return Pointer to vertex shader.
    virtual VertexShader* createVertexShader();

    /// Create tessellation control shader.
    /// @return Pointer to tessellation control shader.
    virtual TessellationControlShader* createTessellationControlShader();

    /// Create tessellation evaluation shader.
    /// @return Pointer to tessellation evaluation shader.
    virtual TessellationEvaluationShader*
        createTessellationEvaluationShader();

    /// Create geometry shader.
    /// @return Pointer to geometry shader.
    virtual GeometryShader* createGeometryShader();

    /// Create fragment shader.
    /// @return Pointer to fragment shader.
    virtual FragmentShader* createFragmentShader();

    /// Create shader program.
    /// @return Pointer to shader program.
    virtual ShaderProgram* createShaderProgram();

protected:
    GLDevice();

private:
    od::graphics::hal::DeviceResourceManager mDeviceResourceManager;

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLDEVICE_HPP */
