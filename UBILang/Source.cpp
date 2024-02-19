#include <iostream>

#include "Lexer.hh"
#include "parser.hh"
#include "Expression.hh"


int main(int argc, char const* argv[])
{ 
    using namespace std;

    
    str code = "word = 2 + 2";
    Lexer A(code);



    for (auto item : A.tokenize())
        cout << str(item.getText()) << endl;

    auto expressions = Parser(A.tokenize()).parse();
    
    for (int32 i = 0; i < expressions.size(); ++i)
        expressions[i]->execute();


    return EXIT_SUCCESS;
}