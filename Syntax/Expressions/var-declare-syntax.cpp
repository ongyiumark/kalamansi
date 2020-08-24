#include "syntax-expressions.h"

using namespace Syntax;

// Declares a variable. Pushes a value into the symbol table.
VarDeclareExpressionSyntax::VarDeclareExpressionSyntax(SyntaxToken var_keyword, SyntaxToken identifier)
    : _var_keyword(var_keyword), _identifier(identifier) {}

VarDeclareExpressionSyntax::~VarDeclareExpressionSyntax() {}

SyntaxKind VarDeclareExpressionSyntax::kind() const
{
    return SyntaxKind::VarDeclareExpression;
}

SyntaxToken* VarDeclareExpressionSyntax::get_var_keyword()
{
    return &_var_keyword;
}

SyntaxToken* VarDeclareExpressionSyntax::get_identifier()
{
    return &_identifier;
}