#ifndef OD_PLATFORM_APPLICATIONFACTORY_HPP
#define OD_PLATFORM_APPLICATIONFACTORY_HPP

#include <memory>

namespace od {
namespace platform {

class Application;

/// Factory class to create Application.
class ApplicationFactory
{
public:
    enum ApplicationType
    {
        APPLICATIONTYPE_DEFAULT
    };

    /// Create application
    /// @param argc Parameter/Argument count
    /// @param argv Parameter/Argument variable array
    /// @param type Try to create this type of ApplicationType
    ///             if poosible
    static std::shared_ptr <Application> createApplication(
            int argc, char** argv,
            ApplicationType type = APPLICATIONTYPE_DEFAULT);

private:
    ApplicationFactory();
    ApplicationFactory(const ApplicationFactory&);
    ApplicationFactory& operator= (const ApplicationFactory&);

};

}
}

#endif /* OD_PLATFORM_APPLICATIONFACTORY_HPP */
