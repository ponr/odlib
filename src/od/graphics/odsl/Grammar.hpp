/// Grammar for ODSL

#ifndef OD_GRAPHICS_ODSL_GRAMMAR_HPP
#define OD_GRAPHICS_ODSL_GRAMMAR_HPP

#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>

namespace qi = boost::spirit::qi;

namespace od {
namespace graphics {
namespace odsl {

template <typename TIterator>
struct Grammar :
        qi::grammar <TIterator>
{
    template <typename TTokenDef>
    Grammar(const TTokenDef& tok)
        : Grammar::base_type(odsl)
    {
        using qi::token;
        using qi::lit;
        using qi::on_error;
        using qi::fail;
        using qi::debug;
        using boost::phoenix::val;
        using boost::phoenix::construct;
        using namespace qi::labels;

        // Start symbol
        odsl = input_block
                >> output_block
                >> *(function)
                >> main_function;

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
                | builtin_output_var) >> lit(';');

        builtin_output_var = token(ID_KW_OD_POSITION);

        statement =
                ( var_definition | assignment /*| if_statement
                | while_statement*/
                | call_statement /*| return_statement*/ )
                > lit(';');

        assignment = (tok.identifier | builtin_output_var)
                >> lit('=') > expression;

        call_statement =
                (tok.identifier >> lit('(') >> lit(')'))
                | (tok.identifier >> lit('(') >> argument_list >> lit(')'));

        var_definition = type >> assignment;

        argument_list = *(argument >> lit(',')) >> argument;

        argument = expression.alias();

        expression =
                expression_add
                | expression_multiply
                | expression_value;

        expression_add =
                (expression_value >> lit('+') >> expression_value)
                | (expression_value >> lit('-') >> expression_value);
        expression_multiply =
                (expression_value >> lit('*') >> expression_value)
                | (expression_value >> lit('/') >> expression_value);

        expression_value =
                (lit('(') > expression > lit(')'))
                | call_statement
                | tok.identifier
                | tok.float_
                | tok.number;

        odsl.name("odsl");
        input_block.name("input_block");
        input_definition.name("input_definition");
        output_block.name("output_block");
        output_definition.name("output_definition");
        builtin_output_var.name("builtin_output_var");
        type_qualifier.name("type_qualifier");
        type.name("type");
        statement.name("statement");
        assignment.name("assignment");
        call_statement.name("call_statement");
        var_definition.name("var_definition");
        argument_list.name("argument_list");
        argument.name("argument");
        expression.name("expression");
        expression_add.name("expression_add");
        expression_multiply.name("expression_multiply");
        expression_value.name("expression_value");
        main_function.name("main_function");
        function_body.name("function_body");

        /*
        debug(odsl);
        debug(input_block);
        debug(input_definition);
        debug(output_block);
        debug(output_definition);
        debug(builtin_output_var);
        debug(type_qualifier);
        debug(type);
        debug(statement);
        debug(assignment);
        debug(call_statement);
        debug(var_definition);
        debug(argument_list);
        debug(argument);
        debug(expression);
        debug(expression_add);
        debug(expression_multiply);
        debug(expression_value);
        debug(main_function);
        debug(function_body);
        */

        on_error<fail>
        (
            odsl
          , std::cout
                << val("Error! Expecting ")
                << _4                               // what failed?
                << val(" here: \"")
                << construct<std::string>(_3, _2)   // iterators to error-pos, end
                << val("\"")
                << std::endl
        );
    }

    typedef qi::rule <TIterator> Rule;

    Rule odsl;

    Rule input_block;
    Rule input_definition;

    Rule output_block;
    Rule output_definition;

    Rule builtin_output_var;

    Rule type_qualifier;
    Rule type;

    Rule statement;
    Rule assignment;
    Rule if_statement;
    Rule while_statement;
    Rule call_statement;
    Rule return_statement;
    Rule var_definition;

    Rule argument_list;
    Rule argument;
    Rule expression;
    Rule expression_add;
    Rule expression_multiply;
    Rule expression_value;

    Rule function;
    Rule main_function;
    Rule function_body;
};

}
}
}

#endif /* OD_GRAPHICS_ODSL_GRAMMAR_HPP */
