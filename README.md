ODlib
=====

This is ODlib, a modern cross-platform graphics/game engine framework library.
Currently project aims to support Android, GNU/Linux, Mac OS X and Windows. 
Windows-port aims to support both OpenGL and Direct3D. In practice, library
could be quite easily ported to any platform that supports 
OpenGL 3 or 4 or ES 2 with native C++ code.

License
-------

ODlib is licensed under GNU Lesser General Public License v3. See LICENSE.

Requirements
------------

General
- Compiler with decent C++11 support (recent versions of Clang or GCC)
- Boost (filesystem, foreach, threads, test, date-time)
- CMake
- libjpeg (for jpeg texture support)
- libpng (for png texture support)
- OpenGL 3 or 4 or ES 2 (embedded devices). In practice, when using graphics hardware
  which doesn't support OpenGL 3 or 4, graphics could be rendered using ES2-mode.
- protobuf
- SWIG
- xz

PC-platforms (GNU/Linux, Mac OS X, Windows)
- GLEW
- GLFW (optional)
- OpenAL
- OpenCL (optional)
- Qt (optional)

Android
- Android SDK & NDK
