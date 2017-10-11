#pragma once
#include <string>
#include "Token.h"
#include "Scanner.h"

class Lexer {
    public:
        Lexer( std::string fname );
        Token get( void );
        void set_debug( void );
        
    private:
        Scanner s;
        void debug( Token t );
        bool DEBUG;

};

