#include "builtin-functions.h"

#include "../Syntax/syntax.h"
#include <iostream>

using namespace Objects;
using namespace Diagnostics;
using namespace Contexts;
using namespace Syntax;

Diagnostics::DiagnosticBag* BuiltInFunctions::_diagnostics;

// Prints to the screen.
Object* BuiltInFunctions::BI_PRINT(Context* context)
{
    Object* obj = context->get_symbol_table()->get_object("value").object;
    std::cout << obj->to_string() << std::endl;
    return new None();
}

// Reads a line as a string.
Object* BuiltInFunctions::BI_INPUT(Context* context)
{
    std::string val;
    getline(std::cin, val);
    return new String(val);
}

// Converts a string to an integer.
Object* BuiltInFunctions::BI_TO_INT(Context* context)
{
    Object* obj = context->get_symbol_table()->get_object("value").object;
    switch (obj->type())
    {
        case Type::STRING:
        {
            std::string text = ((String*)obj)->get_value();

            bool is_valid = true;
            for (char c : text)
                is_valid &= is_digit(c);


            std::istringstream is(text);
            long long x;
            if (is >> x && is_valid) return new Integer(x);
            
            _diagnostics->report_invalid_type(text, type_to_string(Type::INTEGER));
            return Object::none_result;
        }
        case Type::INTEGER:
            return obj;
        case Type::BOOLEAN:
            return new Integer(((Boolean*)obj)->get_value());
        case Type::DOUBLE:
            return new Integer(((Double*)obj)->get_value());
        default:
        {
            _diagnostics->report_invalid_builtin_arguments("BI_TO_INT", 1, type_to_string(obj->type()));
            return Object::none_result;
        }
    }
}