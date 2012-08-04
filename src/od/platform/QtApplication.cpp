#include "QtApplication.hpp"
#include "GLQtWindow.hpp"

#include <QApplication>

namespace od {
namespace platform {

QtApplication::QtApplication(int argc, char ** argv) :
    Application(argc, argv)
{
    mApp = new QApplication(argc, argv);
}

QtApplication::~QtApplication()
{
}

Window* QtApplication::createWindow()
{
    return new GLQtWindow();
}


}
}
