#include <iostream>
#include <string>
#include <fstream>

#include "Parser.h"
#include "tokens.h"

int main( int argc, char *argv[] ) {
    std::string fname = argv[1];
    std::string line;
    std::ifstream fin;
    Parser p;
    p.set_debug();
    token tok;

    fin.open(fname);
    
    while( std::getline( fin, line ) ) {
        std::cout << "parsing: " << line << std::endl;
        p.set( line );
        while( (tok = p.get_token()) != EOL ) {
            std::cout << "\t" << p.get_tok_string() << std::endl;
        }
        std::cout << "\tEOL" << std::endl;
    }
    fin.close();
}
