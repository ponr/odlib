/// OpenGL Version enumeration

#ifndef OD_GRAPHICS_HAL_GL_GLVERSION
#define OD_GRAPHICS_HAL_GL_GLVERSION

namespace od {
namespace graphics {
namespace hal {
namespace gl {

// OpenGL Version enumeration
enum GLVersion
{
    GLVERSION_GLES20, /// OpenGL ES 2.0
    GLVERSION_GL3, /// OpenGL 3.3
    GLVERSION_GL4  /// OpenGL 4.20
};

}
}
}
}

#endif /* OD_GRAPHICS_HAL_GL_GLVERSION */
