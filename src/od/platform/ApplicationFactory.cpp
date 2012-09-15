#include "ApplicationFactory.hpp"
#include "QtApplication.hpp"

namespace od {
namespace platform {

std::shared_ptr<Application> ApplicationFactory::createApplication(
        int argc, char** argv, ApplicationType type)
{
    return std::shared_ptr <Application> (new QtApplication(argc, argv));
}

}
}
