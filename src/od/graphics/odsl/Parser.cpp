#define BOOST_SPIRIT_DEBUG
#define BOOST_SPIRIT_DEBUG_OUT std::cout
#include "Parser.hpp"
#include "Lexer.hpp"
#include "Grammar.hpp"

namespace od {
namespace graphics {
namespace odsl {

Parser::Parser()
{
}

void Parser::parse(const std::string &src)
{
    typedef boost::spirit::lex::lexertl::token<
            const char*, boost::mpl::vector<std::string> >
            TokenType;
    typedef boost::spirit::lex::lexertl::actor_lexer<TokenType> LexerType;
    typedef Lexer<LexerType>::iterator_type IteratorType;

    Lexer<LexerType> lexer;
    Grammar<IteratorType> grammar(lexer);

    char const* first = src.c_str();
    char const* last = &first[src.size()];

    bool ready = boost::spirit::lex::tokenize_and_parse(
                first, last, lexer, grammar);

    if(!ready)
    {
        // TODO: Better error reporting facilities
        std::string rest(first, last);
        std::cerr << "Parsing failed\n"
                  << "stopped at: " << std::endl
                  << rest << std::endl;
    }

    return;
}

}
}
}
