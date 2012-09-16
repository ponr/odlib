#include "ShaderCompiler.hpp"

namespace od {
namespace graphics {
namespace odsl {

ShaderCompiler::ShaderCompiler() :
    mSource(),
    mCompilationSuccess(false),
    mCompilationError()
{
}

ShaderCompiler::~ShaderCompiler()
{
}

void ShaderCompiler::setSource(const std::string& src)
{
    mSource = src;
}

bool ShaderCompiler::compile()
{
    return false;
}

std::string ShaderCompiler::getCompilationError() const
{
    return "";
}

}
}
}
