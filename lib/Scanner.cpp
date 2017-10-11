#include <iostream>
#include "Scanner.h"

// constructors
Scanner::Scanner() {         // default constructor
    DEBUG = false;
}

void Scanner::set_debug( void ) {
    DEBUG = true;
}

void Scanner::debug( char c ) {
    std::cout 
        << "Scan: " 
        << c 
        << " " 
        << (int) c 
        << std::endl;
}


void Scanner::set( std::string fname ) {
    file_name = fname;
    fin.open( fname, std::ios::in );
    if( !fin ) {
        std::cerr << "error: input file not found: "
            << fname
            << std::endl;
        exit(0);
    }
    ll = 0;
    cc = 0;
}

// destructor
Scanner::~Scanner( void ) {
    fin.close();
}

// accessors
char Scanner::getc( void ) {
    if( fin.peek() == EOF) return 0;
    if( fin.peek() == '\n' 
            || fin.peek() == '\r' ) {
        c = fin.get();
        return 10;
    }
    return fin.get();
}

// mutators
void Scanner::pushc( char c ) {
    fin.putback(c);
}

int Scanner::get_line( void ) {
    return ll;
}

int Scanner::get_col( void ) {
    return cc;
}

