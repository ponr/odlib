#include "GLDevice.hpp"
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
    od::graphics::hal::Device()
{
}

GLDevice::~GLDevice()
{
}

std::shared_ptr <od::graphics::hal::Context>
GLDevice::createContext()
{
    return std::shared_ptr <od::graphics::hal::Context> (new GLContext());
}

std::shared_ptr <od::graphics::hal::Texture> GLDevice::createTexture()
{
    return std::shared_ptr <od::graphics::hal::Texture> (new GLTexture());
}

std::shared_ptr <od::graphics::hal::VertexBuffer>
GLDevice::createVertexBuffer()
{
    return std::shared_ptr <od::graphics::hal::VertexBuffer>
            (new GLVertexBuffer());
}

std::shared_ptr <od::graphics::hal::VertexShader>
GLDevice::createVertexShader()
{
    return std::shared_ptr <od::graphics::hal::VertexShader>
            (new GLVertexShader());
}

std::shared_ptr <od::graphics::hal::TessellationControlShader>
GLDevice::createTessellationControlShader()
{
    return std::shared_ptr <od::graphics::hal::TessellationControlShader>
            (new GLTessellationControlShader());
}

std::shared_ptr <od::graphics::hal::TessellationEvaluationShader>
GLDevice::createTessellationEvaluationShader()
{
    return std::shared_ptr <od::graphics::hal::TessellationEvaluationShader>
            (new GLTessellationEvaluationShader());
}

std::shared_ptr <od::graphics::hal::GeometryShader>
GLDevice::createGeometryShader()
{
    return std::shared_ptr <od::graphics::hal::GeometryShader>
            (new GLGeometryShader());
}

std::shared_ptr <od::graphics::hal::FragmentShader>
GLDevice::createFragmentShader()
{
    return std::shared_ptr <od::graphics::hal::FragmentShader>
            (new GLFragmentShader());
}

std::shared_ptr <od::graphics::hal::ShaderProgram>
GLDevice::createShaderProgram()
{
    return std::shared_ptr <od::graphics::hal::ShaderProgram>
            (new GLShaderProgram());
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
    return false;
}

}
}
}
}

