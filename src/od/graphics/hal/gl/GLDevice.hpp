/// GL Device class

#ifndef OD_GRAPHICS_HAL_GL_GLDEVICE_HPP
#define OD_GRAPHICS_HAL_GL_GLDEVICE_HPP

#include "../Device.hpp"
#include "../DeviceResourceManager.hpp"
#include "../../../core/types.hpp"

#include "OpenGL.hpp"

namespace od {
namespace graphics {
namespace hal {

class DeviceFactory;

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
    std::shared_ptr <od::graphics::hal::Context> createContext();

    /// Create texture.
    /// @return Pointer to texture.
    std::shared_ptr <od::graphics::hal::Texture> createTexture();

    /// Create vertex buffer.
    /// @return Pointer to vertex buffer.
    std::shared_ptr <od::graphics::hal::VertexBuffer> createVertexBuffer();

    /// Create vertex shader.
    /// @return Pointer to vertex shader.
    std::shared_ptr <od::graphics::hal::VertexShader> createVertexShader();

    /// Create tessellation control shader.
    /// @return Pointer to tessellation control shader.
    std::shared_ptr <od::graphics::hal::TessellationControlShader>
    createTessellationControlShader();

    /// Create tessellation evaluation shader.
    /// @return Pointer to tessellation evaluation shader.
    std::shared_ptr <od::graphics::hal::TessellationEvaluationShader>
    createTessellationEvaluationShader();

    /// Create geometry shader.
    /// @return Pointer to geometry shader.
    std::shared_ptr <od::graphics::hal::GeometryShader> createGeometryShader();

    /// Create fragment shader.
    /// @return Pointer to fragment shader.
    std::shared_ptr <od::graphics::hal::FragmentShader> createFragmentShader();

    /// Create shader program.
    /// @return Pointer to shader program.
    std::shared_ptr <od::graphics::hal::ShaderProgram> createShaderProgram();

    /// Window resize callback
    /// @param width Width of window
    /// @param height Height of window
    void resize( ODuint16 width, ODuint16 height );

    /// Get type of the device
    /// @return Type of the device
    DeviceType getType() const;

protected:
    GLDevice();

    bool init();

private:
    // Resource manager
    od::graphics::hal::DeviceResourceManager mDeviceResourceManager;

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLDEVICE_HPP */
