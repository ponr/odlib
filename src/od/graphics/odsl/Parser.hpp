/// Parser class

#ifndef OD_GRAPHICS_ODSL_PARSER_HPP
#define OD_GRAPHICS_ODSL_PARSER_HPP

#include <string>

namespace od {
namespace graphics {
namespace odsl {

/// Parser class. Parses ODSL code to AST.
class Parser
{
public:
    /// Parse ODSL code
    /// @param src Source code
    void parse(const std::string& src);

private:
    Parser(const Parser&);
    Parser& operator= (const Parser&);
};

}
}
}

#endif /* OD_GRAPHICS_ODSL_PARSER_HPP */
