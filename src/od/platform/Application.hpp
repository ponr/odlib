#ifndef OD_PLATFORM_APPLICATION_HPP
#define OD_PLATFORM_APPLICATION_HPP

namespace od {
namespace platform {

class Window;

/// Interface Class to handle interaction between Application Platform
/// and ODlib.
/// Handles window creation and event system.
class Application
{
public:
    /// Destructor
    virtual ~Application();

    /// Create window
    /// @return Pointer to window
    virtual Window* createWindow() = 0;

protected:
    Application(int argc, char ** argv);

private:
    Application(const Application&);
    Application& operator= (const Application&);

};

}
}

#endif /* OD_PLATFORM_APPLICATION_HPP */
