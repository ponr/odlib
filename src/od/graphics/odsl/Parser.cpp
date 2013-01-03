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

void Parser::parse(const std::string& src)
{
    // Typedefs for Token, Lexer and Lexer Iterator
    typedef boost::spirit::lex::lexertl::token<
            std::string::const_iterator, // source string iterator type
            boost::mpl::vector<std::string> >
            TokenType;
    typedef boost::spirit::lex::lexertl::actor_lexer<TokenType> LexerType;
    typedef Lexer<LexerType>::iterator_type IteratorType;

    // Create Lexer and Grammar
    Lexer<LexerType> lexer;
    Grammar<IteratorType> grammar(lexer);

    // Iterator for source code to be parsed
    std::string::const_iterator first = src.begin();
    std::string::const_iterator last = src.end();

    // utree AST structure
    boost::spirit::utree tree;

    // Do the actual parsing
    bool ready = boost::spirit::lex::tokenize_and_parse(
                first, last, lexer, grammar, tree);

    if(!ready)
    {
        // TODO: Better error reporting facilities
        // Report error if any.
        std::string rest(first, last);
        std::cerr << "Parsing failed\n"
                  << "stopped at: " << std::endl
                  << rest << std::endl;
        return;
    }

    // Print resulting utree
    std::cout << tree << std::endl;

    return;
}

}
}
}
