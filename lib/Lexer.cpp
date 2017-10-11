#include "Lexer.h"
#include "Scanner.h"
#include "tokens.h"
#include <iostream>

Lexer::Lexer( std::string fname ) {
    s.set( fname );
    DEBUG = false;    
}

// return the next token
 Token Lexer::get( void ) {
    char c = s.getc();
    std::string sym = "";
    sym += c;
    Token tok(sym, CHAR);

    // check for end of line and file
    if(  (int)c == 10 ) {
        tok.name = "ENDL"; 
        tok.tval = ENDL;
    }
    else if( (int)c == 0 ) {
        tok.name = "EOL";
        tok.tval = ENDF;
    }
    // looks like something we need to classify
    if( isalpha(c) ) {
            tok.tval = IDENT;
    }
    else if( isdigit(c) ) {
        tok.tval = NUMBER;
    }
    if( DEBUG ) debug( tok );
    return tok;
}

void Lexer::set_debug( void ) {
    DEBUG = true;
}

void Lexer::debug( Token tok ) {
    std::cout << "\tLexer:";
    if(tok.name == " ")
        std::cout << "<space>";
    else
         std::cout << tok.name;

    std::cout << " " << tok.tval
         << std::endl;
}


    
