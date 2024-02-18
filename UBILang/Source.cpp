#include <iostream>

#include "Lexer.hh"
#include "parser.hh"
#include "Expression.hh"


int main(int argc, char const* argv[])
{ 
    using namespace std;

    
    str code = "3+3*3";
    Lexer A(code);

    for (auto item : A.tokenize())
        cout << str(item.getText()) << endl;


    auto expressions = Parser(A.tokenize()).parse();

    for (int16 i = 0; i < expressions.size(); ++i)
        cout << expressions[i]->eval() << endl;

    return EXIT_SUCCESS;
}