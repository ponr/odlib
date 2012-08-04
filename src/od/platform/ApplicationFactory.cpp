#include "ApplicationFactory.hpp"
#include "QtApplication.hpp"

namespace od {
namespace platform {

Application* ApplicationFactory::createApplication(
        int argc, char** argv, ApplicationType type)
{
    return new QtApplication(argc, argv);
}

}
}
