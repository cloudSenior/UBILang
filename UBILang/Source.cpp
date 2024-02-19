#include <iostream>
#include <fstream>

#include "Lexer.hh"
#include "parser.hh"
#include "Expression.hh"


int main(int argc, char const* argv[])
{ 
    using namespace std;

    str buffer;
    ifstream file("program.ubi");
    
    while (getline(file, buffer)) {
        str code = buffer;

        Lexer lexer(code);

        vec<Token> tokens = lexer.tokenize();
        vec<shared_ptr<Statement>> expressions = move(Parser(tokens).parse());

        for (auto& item: expressions)
            item->execute();
    }

    file.close();
    return EXIT_SUCCESS;
}