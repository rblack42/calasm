#pragma once
#include <string>
#include "tokens.h"

class Token {
    public:
        // constructors
        Token();
        Token( std::string tok, token t );

        std::string name;
        token tval;
};

