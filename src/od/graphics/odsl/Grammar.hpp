/// Grammar for ODSL

#ifndef OD_GRAPHICS_ODSL_GRAMMAR_HPP
#define OD_GRAPHICS_ODSL_GRAMMAR_HPP

#include <boost/spirit/include/qi.hpp>

template <typename Iterator>
struct Grammar : boost::spirit::qi::grammar <Iterator>
{
    template <typename TokenDef>
    Grammar(const TokenDef& tok)
        : Grammar::base_type(start)
    {
    }

    boost::spirit::qi::rule <Iterator> start;
};

#endif /* OD_GRAPHICS_ODSL_GRAMMAR_HPP */
