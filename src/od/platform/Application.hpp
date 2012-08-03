#ifndef OD_PLATFORM_APPLICATION_HPP
#define OD_PLATFORM_APPLICATION_HPP

namespace od {
namespace platform {

class Window;

class Application
{
public:
    /// Destructor
    virtual ~Application();

    /// Create window
    /// @return Pointer to window
    virtual Window* createWindow() = 0;

    /// Set Device to use given Window
    /// @param window Pointer to window
    /// @return Bool to tell if set succeeded or not
    virtual bool setWindow(Window* window) = 0;

    /// Get Window of the Device
    /// @return Pointer to window
    virtual Window* getWindow() = 0;

protected:
    Application(int argc, char ** argv);

private:
    Application(const Application&);
    Application& operator= (const Application&);

};

}
}

#endif /* OD_PLATFORM_APPLICATION_HPP */
