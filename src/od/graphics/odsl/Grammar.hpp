/// Grammar for ODSL

#ifndef OD_GRAPHICS_ODSL_GRAMMAR_HPP
#define OD_GRAPHICS_ODSL_GRAMMAR_HPP

#include <boost/spirit/include/qi.hpp>

template <typename TIterator>
struct Grammar :
        boost::spirit::qi::grammar <TIterator>
{
    template <typename TTokenDef>
    Grammar(const TTokenDef& tok)
        : Grammar::base_type(start)
    {
        using boost::spirit::qi::token;
        using boost::spirit::qi::lit;

        start = input_block >> output_block >> *(function) >> main_function;

        main_function = token(ID_KW_MAIN) >> lit('(') >> lit(')')
                                          >> function_body;

        function_body = lit('{') >> *(statement) >> lit('}');

        input_block = token(ID_KW_INPUT)
                >> lit('{')
                >> *(input_definition)
                >> lit('}');

        type_qualifier = token(ID_KW_UNIFORM)
                | token(ID_KW_ATTRIBUTE)
                | token(ID_KW_VARYING);

        type = token(ID_TYPE_BOOL)
               | token(ID_TYPE_INT)
               | token(ID_TYPE_FLOAT)
               | token(ID_TYPE_VECTOR2)
               | token(ID_TYPE_VECTOR3)
               | token(ID_TYPE_VECTOR4)
               | token(ID_TYPE_BVECTOR2)
               | token(ID_TYPE_BVECTOR3)
               | token(ID_TYPE_BVECTOR4)
               | token(ID_TYPE_MATRIX2)
               | token(ID_TYPE_MATRIX3)
               | token(ID_TYPE_MATRIX4)
               | token(ID_TYPE_TEXTURE2D);

        input_definition = type_qualifier >> type >> tok.identifier
                                          >> lit(';');
        output_block = token(ID_KW_OUTPUT)
                >> lit('{')
                >> *(output_definition)
                >> lit('}');

        output_definition = ((type_qualifier >> type >> tok.identifier)
                | token(ID_KW_OD_POSITION)) >> lit(';');

        statement =
                (assignment | if_statement | while_statement
                | call_statement | return_statement | var_definition)
                >> lit(';');

        assignment = tok.identifier >> lit('=') >> expression;

        call_statement = tok.identifier
                >> lit('(')
                >> *(argument >> lit(','))
                >> argument
                >> lit(')');

        var_definition = type >> (tok.identifier | assignment);

        argument = expression.alias();

        expression =
                (expression >> lit('+') >> expression)
                | (expression >> lit('-') >> expression)
                | (expression >> lit('*') >> expression)
                | (expression >> lit('/') >> expression)
                | (lit('(') >> expression >> lit(')'))
                | tok.identifier
                | tok.number
                | call_statement;

    }

    typedef boost::spirit::qi::rule <TIterator> RuleType;

    RuleType start;

    RuleType input_block;
    RuleType input_definition;

    RuleType output_block;
    RuleType output_definition;

    RuleType type_qualifier;
    RuleType type;

    RuleType statement;
    RuleType assignment;
    RuleType if_statement;
    RuleType while_statement;
    RuleType call_statement;
    RuleType return_statement;
    RuleType var_definition;

    RuleType argument;
    RuleType expression;

    RuleType function;
    RuleType main_function;
    RuleType function_body;
};

#endif /* OD_GRAPHICS_ODSL_GRAMMAR_HPP */
