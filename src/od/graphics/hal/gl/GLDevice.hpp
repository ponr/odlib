/// GL Device class

#ifndef OD_GRAPHICS_HAL_GL_GLDEVICE_HPP
#define OD_GRAPHICS_HAL_GL_GLDEVICE_HPP

#include "../Device.hpp"
#include "../DeviceFactory.hpp"
#include "../DeviceResourceManager.hpp"
#include "../../../core/types.hpp"

#ifdef GLFW
#include <GL/glfw.h>
#endif /* GLFW */

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
    Context* createContext();

    /// Create texture.
    /// @return Pointer to texture.
    Texture* createTexture();

    /// Create vertex buffer.
    /// @return Pointer to vertex buffer.
    VertexBuffer* createVertexBuffer();

    /// Create vertex shader.
    /// @return Pointer to vertex shader.
    VertexShader* createVertexShader();

    /// Create tessellation control shader.
    /// @return Pointer to tessellation control shader.
    TessellationControlShader* createTessellationControlShader();

    /// Create tessellation evaluation shader.
    /// @return Pointer to tessellation evaluation shader.
    TessellationEvaluationShader*
        createTessellationEvaluationShader();

    /// Create geometry shader.
    /// @return Pointer to geometry shader.
    GeometryShader* createGeometryShader();

    /// Create fragment shader.
    /// @return Pointer to fragment shader.
    FragmentShader* createFragmentShader();

    /// Create shader program.
    /// @return Pointer to shader program.
    ShaderProgram* createShaderProgram();

    /// Window resize callback
    void resize( ODuint16 width, ODuint16 height );



protected:
    GLDevice();

    bool init();

private:
#ifdef GLFW
    void GLFWCALL GLFW_ResizeCallback( int width, int height );
#endif /* GLFW */

    // Resource manager
    od::graphics::hal::DeviceResourceManager mDeviceResourceManager;

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLDEVICE_HPP */
