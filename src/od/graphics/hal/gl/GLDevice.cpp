#include "GLDevice.hpp"
#include "GLContext.hpp"
#include "GLVertexShader.hpp"
#include "GLTessellationControlShader.hpp"
#include "GLTessellationEvaluationShader.hpp"
#include "GLGeometryShader.hpp"
#include "GLFragmentShader.hpp"
#include "GLShaderProgram.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

#ifdef GLFW
void GLFWCALL GLDevice::GLFW_ResizeCallback( int width, int height )
{
    resize(width, height);
}
#endif /* GLFW */

GLDevice::GLDevice() :
    od::graphics::hal::Device()
{
}

GLDevice::~GLDevice()
{
    glfwTerminate();
}

od::graphics::hal::Context* GLDevice::createContext()
{
    return new GLContext();
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

bool GLDevice::init()
{
#ifdef GLFW
    if(!glfwInit())
    {
        return false;
    }

    if(!glfwOpenWindow(300, 300, 0, 0, 0, 0, 0, 0, GLFW_WINDOW))
    {
        glfwTerminate();
        return false;
    }
#else
    return false;
#endif /* GLFW */
}

}
}
}
}

