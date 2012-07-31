#include "GLDevice.hpp"
#include "GLWindow.hpp"
#include "GLContext.hpp"
#include "GLVertexBuffer.hpp"
#include "GLVertexShader.hpp"
#include "GLTessellationControlShader.hpp"
#include "GLTessellationEvaluationShader.hpp"
#include "GLGeometryShader.hpp"
#include "GLFragmentShader.hpp"
#include "GLShaderProgram.hpp"
#include "GLTexture.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

GLDevice::GLDevice() :
    od::graphics::hal::Device(),
    mWindow(0),
    mGLWindow(0)
{
}

GLDevice::~GLDevice()
{
    glfwTerminate();
}

od::graphics::hal::Window* GLDevice::createWindow()
{
    return 0;
}

bool GLDevice::setWindow(Window *window)
{
    mWindow = window;
    mGLWindow = dynamic_cast <GLWindow*> (mWindow);

    if(mGLWindow == 0)
    {
        return false;
    }

    return true;
}

od::graphics::hal::Window* GLDevice::getWindow()
{
    return mWindow;
}

od::graphics::hal::Context* GLDevice::createContext()
{
    return new GLContext();
}

od::graphics::hal::Texture* GLDevice::createTexture()
{
    return new GLTexture();
}

od::graphics::hal::VertexBuffer* GLDevice::createVertexBuffer()
{
    return new GLVertexBuffer();
}

od::graphics::hal::VertexShader* GLDevice::createVertexShader()
{
    return new GLVertexShader();
}

od::graphics::hal::TessellationControlShader*
    GLDevice::createTessellationControlShader()
{
    return new GLTessellationControlShader();
}

od::graphics::hal::TessellationEvaluationShader*
    GLDevice::createTessellationEvaluationShader()
{
    return new GLTessellationEvaluationShader();
}

od::graphics::hal::GeometryShader* GLDevice::createGeometryShader()
{
    return new GLGeometryShader();
}

od::graphics::hal::FragmentShader* GLDevice::createFragmentShader()
{
    return new GLFragmentShader();
}

od::graphics::hal::ShaderProgram* GLDevice::createShaderProgram()
{
    return new GLShaderProgram();
}

void GLDevice::resize(ODuint16 width, ODuint16 height)
{
    // TODO: Resize code
}

DeviceType GLDevice::getType() const
{
    return od::graphics::hal::DEVICETYPE_OPENGLES2;
}

bool GLDevice::init()
{
#ifdef GLFW
    if(!glfwInit())
    {
        return false;
    }

    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
    if(!glfwOpenWindow(300, 300, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
    {
        glfwTerminate();
        return false;
    }

    return true;
#else
    return false;
#endif /* GLFW */
}

}
}
}
}

