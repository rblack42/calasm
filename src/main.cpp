#include <iostream>
#include <string>

#include "Lexer.h"
#include "Token.h"

std::string version = "0.2";
std::string fname;

int main(int argc, char *argv[]) {
    int exit_code;
    Token tok;

    std::cout << "CALasm (v" << version << ")" << std::endl;

    if(argc != 2) {
        std::cerr << "\tno input file provided" << std::endl;
        exit(0);
    }
    // create lexer
    Lexer l(argv[1]);
    l.set_debug();
    
    // run the scanner

    std::cout << "\trunning..." << std::endl;
    while( true ) {
        tok = l.get();
        if(tok.tval == ENDF) break;
    }

    std::cout << "\tprocessing finished..." << std::endl;
    return 0;
}
