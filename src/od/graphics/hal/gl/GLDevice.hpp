/// GL Device class

#ifndef OD_GRAPHICS_HAL_GL_GLDEVICE_HPP
#define OD_GRAPHICS_HAL_GL_GLDEVICE_HPP

#include "../Device.hpp"
#include "../DeviceResourceManager.hpp"
#include "../../../core/types.hpp"

#include "OpenGL.hpp"

#ifdef GLFW
#include <GL/glfw.h>
#endif /* GLFW */

namespace od {
namespace graphics {
namespace hal {

class DeviceFactory;

namespace gl {

class GLWindow;

/// GL Device class
class GLDevice : public od::graphics::hal::Device
{
    friend class od::graphics::hal::DeviceFactory;

public:

    virtual ~GLDevice();
    // Resource creation

    /// Create window
    /// @return Pointer to window
    Window* createWindow();

    /// Set Device to use given Window
    /// @param window Pointer to window
    /// @return Bool to tell if set succeeded or not
    bool setWindow(Window* window);

    /// Get Window of the Device
    /// @return Pointer to window
    Window* getWindow();

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

    od::graphics::hal::Window* mWindow;
    od::graphics::hal::gl::GLWindow* mGLWindow;

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLDEVICE_HPP */
