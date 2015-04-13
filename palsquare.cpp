/*
TASK: palsquare
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <algorithm>

#define MAXN 300

using namespace std;

int b;

string chars = "0123456789ABCDEFGHIJ";

string from_dec_to_base( int num, int base ) {

    string ret = "";
    
    while ( num > 0 ) {
   
        ret = ( chars[ num % base ] ) + ret;
        num /= base;
        
    }
    
    return ( ret );

}

bool is_pal( string tmp ) {

    for ( int i = 0; i < tmp.size()/2; ++i )
        if ( tmp[i] != tmp[ tmp.size()-i-1 ] )
            return ( false );
            
    return ( true );

}

int main( ) {

    freopen( "palsquare.in", "r", stdin );
    freopen( "palsquare.out", "w", stdout );

    scanf( "%d", &b );
    
    for ( int i = 1; i <= MAXN; ++i ) {
        string square = from_dec_to_base( i * i, b );
        if ( is_pal( square ) ) {
            printf( "%s %s\n", from_dec_to_base( i, b ).c_str(), square.c_str() );
        }
    }

    return 0;

}