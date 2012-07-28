/// Device interface
#ifndef OD_GRAPHICS_HAL_DEVICE_HPP
#define OD_GRAPHICS_HAL_DEVICE_HPP

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
    virtual Context* createContext() = 0;

    /// Create texture.
    /// @return Pointer to texture.
    virtual Texture* createTexture() = 0;

    /// Create vertex buffer.
    /// @return Pointer to vertex buffer.
    virtual VertexBuffer* createVertexBuffer() = 0;

    /// Create vertex shader.
    /// @return Pointer to vertex shader.
    virtual VertexShader* createVertexShader() = 0;

    /// Create tessellation control shader.
    /// @return Pointer to tessellation control shader.
    virtual TessellationControlShader* createTessellationControlShader() = 0;

    /// Create tessellation evaluation shader.
    /// @return Pointer to tessellation evaluation shader.
    virtual TessellationEvaluationShader*
        createTessellationEvaluationShader() = 0;

    /// Create geometry shader.
    /// @return Pointer to geometry shader.
    virtual GeometryShader* createGeometryShader() = 0;

    /// Create fragment shader.
    /// @return Pointer to fragment shader.
    virtual FragmentShader* createFragmentShader() = 0;

    /// Create shader program.
    /// @return Pointer to shader program.
    virtual ShaderProgram* createShaderProgram() = 0;

protected:
    Device();

private:
    Device(const Device&);
    Device& operator= (const Device&);
};

}
}
}

#endif /* OD_GRAPHICS_HAL_DEVICE_HPP */
