#pragma once
#include <string>
#include <fstream>

class Scanner {
    public:
        // constructor
        Scanner();
        Scanner( std::string name );

        // destructor
        ~Scanner( void );

        // accessors
        char getc( void );              // fetch char for processing
        int get_line( void);            // current line number
        int get_col( void );            // get current column
        
        // mutators
        void set( std::string fname );  // scan this file
        void pushc( char c );           // push c back onto stream
        void set_debug( void );         // enable debug messages
    private:
        bool DEBUG;
        std::ifstream fin;              // input file
        std::string file_name;          // processing this file
        int cc;                         // column number
        int ll;                         // current line
        char c;                         // current char
        void debug( char c );           // display debug line
};

