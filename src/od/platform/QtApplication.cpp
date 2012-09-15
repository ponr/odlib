#include "QtApplication.hpp"
#include "GLQtWindow.hpp"

#include <QApplication>

namespace od {
namespace platform {

QtApplication::QtApplication(int argc, char ** argv) :
    Application(argc, argv),
    mApp(0)
{
    // Initialize new QApplication
    mApp = new QApplication(argc, argv);
}

QtApplication::~QtApplication()
{
    // Free initialized QApplication
    delete mApp;
    mApp = 0;
}

std::shared_ptr <Window> QtApplication::createWindow()
{
    // Return pointer to new GLQtWindow
    return std::shared_ptr <Window> (new GLQtWindow());
}


}
}
