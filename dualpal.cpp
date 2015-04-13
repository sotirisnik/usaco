/*
TASK: dualpal
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n, s, cnt;

string chars = "0123456789";

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

    freopen( "dualpal.in", "r", stdin );
    freopen( "dualpal.out", "w", stdout );
    
    scanf( "%d %d", &n, &s );
    
    while ( n > 0 ) {

        ++s;
        
        cnt = 0;
        
        for ( int i = 2; cnt < 2 && i <= 10; ++i )
            if ( is_pal( from_dec_to_base( s, i ) ) ) {
                ++cnt;
            }
            
        if ( cnt == 2 ) {
            printf( "%d\n", s );
            --n;
        }
    
    }
    
    return 0;

}