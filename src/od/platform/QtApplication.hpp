#ifndef OD_PLATFORM_QTAPPLICATION_HPP
#define OD_PLATFORM_QTAPPLICATION_HPP

#include "Application.hpp"
#include <QApplication>

namespace od {
namespace platform {

class Window;

/// Interface Class to handle interaction between QtApplication Platform
/// and ODlib.
/// Handles window creation and event system.
class QtApplication : public Application
{
public:
    QtApplication(int argc, char ** argv);

    /// Destructor
    virtual ~QtApplication();

    /// Create window
    /// @return Pointer to window
    virtual std::shared_ptr <Window> createWindow();

protected:

private:
    QApplication* mApp;

    QtApplication(const QtApplication&);
    QtApplication& operator= (const QtApplication&);

};

}
}

#endif /* OD_PLATFORM_QTAPPLICATION_HPP */
