#ifndef OD_PLATFORM_APPLICATION_HPP
#define OD_PLATFORM_APPLICATION_HPP

namespace od {
namespace platform {

class Application
{
public:
    /// Destructor
    virtual ~Application();

protected:
    Application(int argc, char ** argv);

private:
    Application(const Application&);
    Application& operator= (const Application&);

};

}
}

#endif /* OD_PLATFORM_APPLICATION_HPP */
