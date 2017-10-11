#include "Token.h"
#include <string>
#include "tokens.h"

std::string token_str[] = { 
    "UNKNOWN",
    "ENDL",
    "ENDF",
    "CHAR",
    "IDENT",
    "NUMBER"
};

// constructor
Token::Token() {
}

Token::Token( std::string s, token t ) {
    name = s;
    tval = t;
}
