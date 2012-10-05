/// Lexer for ODSL

#ifndef OD_GRAPHICS_ODSL_LEXER_HPP
#define OD_GRAPHICS_ODSL_LEXER_HPP

#include <boost/spirit/include/lex_lexertl.hpp>

template <typename LexerType>
struct Lexer : boost::spirit::lex::lexer <LexerType>
{
public:
    Lexer()
    {
        this->self.add_pattern
                ("STRING", "\\\"[^\n\"]+\\\"")
                ("NUMBER", "[0-9]+")
                ("IDENTIFIER", "[a-zA-Z][a-zA-Z0-9]*")
        ;

        string = "{STRING}";
        number = "{NUMBER}";
        identifier = "{IDENTIFIER}";

        this->self.add
                (string)
                (number)
                (identifier)
        ;
    }
private:
    boost::spirit::lex::token_def <std::string> string;
    boost::spirit::lex::token_def <std::string> number;
    boost::spirit::lex::token_def <std::string> identifier;
};

#endif /* OD_GRAPHICS_ODSL_LEXER_HPP */
