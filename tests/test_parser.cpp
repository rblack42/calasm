#include "catch.hpp"
#include "Parser.h"
#include "tokens.h"

TEST_CASE( "test comment lines skipped", "parser" ) {
    std::string comment_line1 = ";this is a comment";
    std::string comment_line2 = "   ;this is a comment";
    std::string comment_line3 = ";";
    Parser p;
    p.set( comment_line1 );
    REQUIRE( p.get_token() == EOL );
    p.set( comment_line2 );
    REQUIRE( p.get_token() == EOL );
    p.set( comment_line3 );
    REQUIRE( p.get_token() == EOL );
}

TEST_CASE( "test identifier is matched", "parser" ) {
    std::string test_line = "MOV 123 reg lit";
    Parser p;
    p.set( test_line );
    token t = p.get_token();
    REQUIRE( t == IDENT );
    REQUIRE( p.get_tok_string() == "MOV");
}

TEST_CASE( "test number is matched", "parser" ) {
    Parser p;
    std::string test_line = "MOV 123 reg lit";
    p.set( test_line );
    token t = p.get_token();
    t = p.get_token();
    REQUIRE( t == NUMBER );
    REQUIRE( p.get_tok_string() == "123" );
}

TEST_CASE( "test general line parses", "parser" ) {
    Parser p;
    std::string general = "label:   MOV   123, 456 ; comment";
    p.set( general );
    REQUIRE( p.get_token() == IDENT );
    REQUIRE( p.get_token() == COLON );
    REQUIRE( p.get_token() == IDENT );
    REQUIRE( p.get_token() == NUMBER );
    REQUIRE( p.get_token() == COMMA );
    REQUIRE( p.get_token() == NUMBER );
    REQUIRE( p.get_token() == EOL );
}

