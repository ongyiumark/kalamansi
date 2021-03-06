#include "initialize.h"
#include "../constants.h"
#include <iostream>

using Evaluators::Evaluator;

Contexts::SymbolTable global_symbol_table = Contexts::SymbolTable(nullptr);
Contexts::Context context("<program>", nullptr, global_symbol_table);

// Create Builtin 
void add_builtin_function(std::string name, std::vector<std::string> arg_names)
{
    Objects::Object* func = new Objects::Function(name, arg_names, nullptr, true);
    context.get_symbol_table()->set_object(name, func);
}

void Evaluators::initialize()
{
    add_builtin_function(BI_INPUT, {});
    add_builtin_function(BI_PRINT, {"value"});
    add_builtin_function(BI_SPLIT, {"value", "delimiter"});
    add_builtin_function(BI_SIZE, {"value"});
    add_builtin_function(BI_TYPE, {"value"});
    add_builtin_function(BI_TO_BOOL, {"value"});
    add_builtin_function(BI_TO_INT, {"value"});
    add_builtin_function(BI_TO_DOUBLE, {"value"});
    add_builtin_function(BI_TO_STRING, {"value"});
    add_builtin_function(BI_SET_INDEX, {"collection", "index", "value"});
}

void Evaluators::run(std::string &script, bool show_tree, bool show_return, bool is_shell)
{
    Diagnostics::DiagnosticBag::script = script;
    Syntax::Parser parser(script, show_return);
    Syntax::SyntaxNode* root = parser.parse();

    if (show_tree) Syntax::pretty_print(root);

    Objects::Object* answer = nullptr;
    if (!Diagnostics::DiagnosticBag::size()) 
        answer = Evaluator::evaluate(context, root);

    Diagnostics::DiagnosticBag::print();

    // If the List only has one element, print that element.
    if (!Diagnostics::DiagnosticBag::size() && show_return && answer != nullptr) 
    {
        if (answer->type() == Objects::Type::LIST && ((Objects::List*)answer)->get_size() == 1)
            std::cout << ((Objects::List*)answer)->get_value(0)->to_string();
        else std::cout << answer->to_string();
        std::cout << "\n" << std::endl;
    }

    delete answer;
    if (!is_shell) delete root;
    Diagnostics::DiagnosticBag::clear();
    Evaluator::clear();
}