#include "catch.hpp"
#include "Parser.h"
#include "tokens.h"



int check_size( std::string line ) {
    Parser p;
    char c;
    p.set( line );
    int i = -1;
    do{
        c = p.getch();
        i++;
    } while( c != 0 );
    return i;
}

TEST_CASE( "test getch scans all characters in line", "parser" ) {
    std::string test_line = "MOV 123 reg lit";
    std::string empty_line = "";
    int size = test_line.size();
    REQUIRE( check_size( test_line ) == size );
    size = empty_line.size();
    REQUIRE( check_size( empty_line ) == size );
}
