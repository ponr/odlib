/// Lexer for ODSL

#ifndef OD_GRAPHICS_ODSL_LEXER_HPP
#define OD_GRAPHICS_ODSL_LEXER_HPP

#include <boost/spirit/include/lex_lexertl.hpp>

namespace od {
namespace graphics {
namespace odsl {

enum TokenID
{
    ID_FLOAT = 1000,
    ID_NUMBER,
    ID_IDENTIFIER,
    ID_KW_INPUT,
    ID_KW_OUTPUT,
    ID_KW_UNIFORM,
    ID_KW_ATTRIBUTE,
    ID_KW_VARYING,
    ID_KW_OD_POSITION,
    ID_KW_MAIN,
    ID_TYPE_BOOL,
    ID_TYPE_INT,
    ID_TYPE_FLOAT,
    ID_TYPE_VECTOR2,
    ID_TYPE_VECTOR3,
    ID_TYPE_VECTOR4,
    ID_TYPE_BVECTOR2,
    ID_TYPE_BVECTOR3,
    ID_TYPE_BVECTOR4,
    ID_TYPE_MATRIX2,
    ID_TYPE_MATRIX3,
    ID_TYPE_MATRIX4,
    ID_TYPE_TEXTURE2D,
    ID_FUNC_MIN,
    ID_FUNC_MAX,
    ID_FUNC_DOT,
};

template <typename TLexer>
struct Lexer : boost::spirit::lex::lexer <TLexer>
{
    Lexer()
    {
        // Regular expressions for literals and identifiers
        this->self.add_pattern
                ("FLOAT", "[0-9]+\\.[0-9]+")
                ("NUMBER", "[0-9]+")
                ("IDENTIFIER", "[a-zA-Z][a-zA-Z0-9_]*")
        ;

        // Set tokens to use corresponding regular expressions
        float_ = "{FLOAT}";
        number = "{NUMBER}";
        identifier = "{IDENTIFIER}";

        // Single character tokens
        this->self = boost::spirit::lex::token_def<>
                ('(') | ')' | '{' | '}' | '=' | ';'
                | '+' | '-' | '*' | '/' | ','
        ;

        // Keyword and literal tokens
        this->self.add
                // Keywords
                ("input", ID_KW_INPUT)
                ("output", ID_KW_OUTPUT)
                ("main", ID_KW_MAIN)

                // Type qualifiers
                ("uniform", ID_KW_UNIFORM)
                ("attribute", ID_KW_ATTRIBUTE)
                ("varying", ID_KW_VARYING)

                // Types
                ("bool", ID_TYPE_BOOL)
                ("int", ID_TYPE_INT)
                ("float", ID_TYPE_FLOAT)
                ("Vector2", ID_TYPE_VECTOR2)
                ("Vector3", ID_TYPE_VECTOR3)
                ("Vector4", ID_TYPE_VECTOR4)
                ("BVector2", ID_TYPE_BVECTOR2)
                ("BVector3", ID_TYPE_BVECTOR3)
                ("BVector4", ID_TYPE_BVECTOR4)
                ("Matrix2", ID_TYPE_MATRIX2)
                ("Matrix3", ID_TYPE_MATRIX2)
                ("Matrix4", ID_TYPE_MATRIX2)
                ("Texture2D", ID_TYPE_TEXTURE2D)

                // Output literal keywords
                ("od_position", ID_KW_OD_POSITION)

                (float_, ID_FLOAT)
                (number, ID_NUMBER)
                (identifier, ID_IDENTIFIER)
        ;

        // Ignore whitespace
        this->self +=
                boost::spirit::lex::string("[ \\t\\n]+")
                [
                    boost::spirit::lex::_pass =
                    boost::spirit::lex::pass_flags::pass_ignore
                ]
        ;

        // Ignore C-style comments
        this->self +=
                boost::spirit::lex::string(
                    "\\/\\*[^*]*\\*+([^/*][^*]*\\*+)*\\/")
                [
                    boost::spirit::lex::_pass =
                    boost::spirit::lex::pass_flags::pass_ignore
                ]
        ;
    }

    boost::spirit::lex::token_def <std::string> float_;
    boost::spirit::lex::token_def <std::string> number;
    boost::spirit::lex::token_def <std::string> identifier;
};

}
}
}

#endif /* OD_GRAPHICS_ODSL_LEXER_HPP */
