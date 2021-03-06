#pragma once

#include <vector>
#include <string>

#include "position.h"

namespace Diagnostics
{
    // Refer to diagnostic.cpp.
    class Diagnostic final
    {
    private:
        std::string _message;
        Position _pos;
    public:
        Diagnostic(std::string& message, Position pos);
        std::string get_message() const;
    };
    
    // Refer to diagnostic-bag.ccp.
    class DiagnosticBag final
    {
    private:
        static std::vector<Diagnostic> _diagnostics;
        static void report(std::string message, Position pos);
    public:
        DiagnosticBag();
        static std::string script;

        static int size();
        static Diagnostic diagnostic(int i);
        static std::vector<Diagnostic> diagnostics();
        static void print();
        static void clear();
        
        static void report_bad_character(char c, Position pos);
        static void report_invalid_type(std::string text, std::string type, Position pos);
        static void report_expected_character(char c, Position pos);
        static void report_unexpected_token(std::string actual, std::string expected, Position pos);
        static void report_illegal_binary_operation(std::string left, std::string operation, std::string right, Position pos);
        static void report_illegal_unary_operation(std::string operation, std::string operand, Position pos);
        static void report_unknown_syntax(std::string syntax, Position pos);
        static void report_unexpected_type(std::string acutal, std::string expected, Position pos);
        static void report_invalid_assign(std::string actual, std::string expected, Position pos);
        static void report_undeclared_identifier(std::string identifier, Position pos);
        static void report_illegal_arguments(int actual, int expected, std::string name, Position pos);
        static void report_unreachable_code(std::string info, Position pos);
        static void report_invalid_builtin_arguments(std::string name, int i, std::string type, Position pos);
    };
}