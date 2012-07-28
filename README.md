ODlib
=====

This is ODlib, a cross-platform game engine library project which aims in fast 
prototyping of games. Currently supported platforms are Android, GNU/Linux, Mac OS X
and Windows. Virtually library could be quite easily ported to any platform that 
supports OpenGL 3 or 4 or ES 2 with native C++ code.

License
-------

ODlib is licensed under GNU Lesser General Public License v3. See LICENSE.

Requirements
------------

General
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
- GLFW
- OpenAL
- OpenCL (optional)

Android
- Android SDK & NDK
