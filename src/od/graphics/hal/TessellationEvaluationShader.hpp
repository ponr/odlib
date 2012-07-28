/// TessellationEvaluation Shader base class

#ifndef OD_GRAPHICS_HAL_TESSELLATIONEVALUATIONSHADER_HPP
#define OD_GRAPHICS_HAL_TESSELLATIONEVALUATIONSHADER_HPP

#include "Shader.hpp"

namespace od {
namespace graphics {
namespace hal {

/// TessellationEvaluation Shader base class
class TessellationEvaluationShader : public Shader
{
public:
    /// Destructor
    virtual ~TessellationEvaluationShader();

protected:
    TessellationEvaluationShader();

private:
    TessellationEvaluationShader(const TessellationEvaluationShader&);
    TessellationEvaluationShader& operator= (const TessellationEvaluationShader&);

};

}
}
}

#endif /* OD_GRAPHICS_HAL_TESSELLATIONEVALUATIONSHADER_HPP */
