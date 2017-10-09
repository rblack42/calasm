#pragma once

#include <string>
#include "tokens.h"

class Parser {
    public:
        Parser();
        void set_debug( void );
        void run( std::string line );
        void set( std::string line );
        char getch( void );
        token get_token( void );
        void skip_white( void );
        std::string get_tok_string( void );

    private:
        bool DEBUG;
        std::string current_line;
        std::string tok_string;
        int cc; // location of next char to read
        int ll; // size of current line
};
        
