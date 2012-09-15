/// Device interface
#ifndef OD_GRAPHICS_HAL_DEVICE_HPP
#define OD_GRAPHICS_HAL_DEVICE_HPP

#include "DeviceType.hpp"

#include <memory>

namespace od {
namespace graphics {
namespace hal {

class Context;
class Texture;
class VertexBuffer;
class VertexShader;
class TessellationControlShader;
class TessellationEvaluationShader;
class GeometryShader;
class FragmentShader;
class ShaderProgram;

/// Device class.
/// Handles allocation of hardware resources.
class Device
{
public:
    /// Destructor
    virtual ~Device();

    // Resource creation

    /// Create context.
    /// @return Pointer to context.
    virtual std::shared_ptr <Context> createContext() = 0;

    /// Create texture.
    /// @return Pointer to texture.
    virtual std::shared_ptr <Texture> createTexture() = 0;

    /// Create vertex buffer.
    /// @return Pointer to vertex buffer.
    virtual std::shared_ptr <VertexBuffer> createVertexBuffer() = 0;

    /// Create vertex shader.
    /// @return Pointer to vertex shader.
    virtual std::shared_ptr <VertexShader> createVertexShader() = 0;

    /// Create tessellation control shader.
    /// @return Pointer to tessellation control shader.
    virtual std::shared_ptr <TessellationControlShader>
    createTessellationControlShader() = 0;

    /// Create tessellation evaluation shader.
    /// @return Pointer to tessellation evaluation shader.
    virtual std::shared_ptr <TessellationEvaluationShader>
    createTessellationEvaluationShader() = 0;

    /// Create geometry shader.
    /// @return Pointer to geometry shader.
    virtual std::shared_ptr <GeometryShader> createGeometryShader() = 0;

    /// Create fragment shader.
    /// @return Pointer to fragment shader.
    virtual std::shared_ptr <FragmentShader> createFragmentShader() = 0;

    /// Create shader program.
    /// @return Pointer to shader program.
    virtual std::shared_ptr <ShaderProgram> createShaderProgram() = 0;

    /// Get type of the device
    /// @return Type of the device
    virtual DeviceType getType() const = 0;

protected:
    Device();

    /// Derived class must implement this
    virtual bool init() = 0;

private:
    Device(const Device&);
    Device& operator= (const Device&);
};

}
}
}

#endif /* OD_GRAPHICS_HAL_DEVICE_HPP */
