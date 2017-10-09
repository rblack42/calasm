#include "Parser.h"
#include <iostream>

// constructor
Parser::Parser() {
    DEBUG = false;
}

// load line for process (used in tests)
void Parser::set( std::string line ) {
    current_line = line;
    cc = 0;
    ll = line.size();
}

void Parser::set_debug( void ) {
    DEBUG = true;
}

// get next character 0 = EOL
char Parser::getch( void ) {
    char c;
    if( cc >= ll ) {
        if( DEBUG ) std::cout << "\tgetch:EOL" << std::endl;
        return 0;
    }
    c = current_line[cc++];
    if( DEBUG ) std::cout << "\tgetch:" << c << std::endl;
    return c;
}

// ignore white space (spaces only)
void Parser::skip_white( void ) {
    char c;
    while( (c = getch()) == ' ');
    cc--;
}

// fetch the next token in the line
token Parser::get_token( void ) {
    char c;
    skip_white();
    c = getch();
    if( c == 0 ) {
        if( DEBUG ) std::cout << "get_token:EOL" << std::endl;
        return EOL;
    }
    if( c == ';' ) {
        tok_string = "comment";
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        cc = ll;    // skip rest of line
        return EOL;
    }
    if( c == ':' ) {
        tok_string = ":";
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        return COLON;
    }
    if( c == ',' ) {
        tok_string = ",";
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        return COMMA;
    }
    if( c == '[' ) {
        tok_string = "[";
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        return LBR;
    }
    if( c == ']' ) {
        tok_string = "]";
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        return RBR;
    }

    // check identifiers (or directives)
    if( isalpha(c) || c == '.') {
        tok_string = c;
        while( isalpha(c = getch()) )
            tok_string += c;
        if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
        cc--;

        // check reserved words
        if( tok_string == "DB") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return DB;
        } else if( tok_string == "DW") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return DW;
        } else if( tok_string == "BYTE") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return BYTE;
        } else if( tok_string == "WORD") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return WORD;
        } else if( tok_string == ".data") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return DATADEC;
        } else if( tok_string == ".code") {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return CODEDEC;
        } else {
            if( DEBUG ) std::cout << "get_token:" << tok_string << std::endl;
            return IDENT;
        }
        return ERROR;
    }

    // check numbers
    if( isdigit(c) ) {
        tok_string = c;
        while( isdigit(c = getch()) ) {
            tok_string += c;
        }
        cc--;
        return NUMBER;
    }
    return ERROR;
}

// return the token string
std::string Parser::get_tok_string( void ) {
    return tok_string;
}

