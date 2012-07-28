/// GL TessellationEvaluationShader Object class

#ifndef OD_GRAPHICS_HAL_GL_GLTESSELLATIONEVALUATIONSHADER_HPP
#define OD_GRAPHICS_HAL_GL_GLTESSELLATIONEVALUATIONSHADER_HPP

#include "../TessellationEvaluationShader.hpp"

namespace od {
namespace graphics {
namespace hal {
namespace gl {

/// GL TessellationEvaluationShader Object class
class GLTessellationEvaluationShader :
    public od::graphics::hal::TessellationEvaluationShader
{
public:
    GLTessellationEvaluationShader();
    virtual ~GLTessellationEvaluationShader();

};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLTESSELLATIONEVALUATIONSHADER_HPP */
