/*
TASK: transform
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 11

using namespace std;

struct state {
    char text[MAXN][MAXN];
};

int n;
state start, final;

bool operator ==( const state &a, const state &b ) {

    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            if ( a.text[i][j] != b.text[i][j] )
                return ( false );
        }
    }
    
    return ( true );

}

state clockwise( state tmp ) {

    state ret;
    
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j )
            ret.text[i][j] = tmp.text[n-j-1][i];
    
    return ( ret );

}

state reflect( state tmp ) {

    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n/2; ++j )
            swap( tmp.text[i][j], tmp.text[i][n-j-1] );
        
    return ( tmp );

}

void print( state tmp ) {

    for ( int i = 0; i < n; ++i )
        printf( "%s\n", tmp.text[i] );

}

int main( ) {

    freopen( "transform.in", "r", stdin );
    freopen( "transform.out", "w", stdout );

    scanf( "%d", &n );

    for ( int i = 0; i < n; ++i )
        scanf( "%s", start.text[i] );
        
    for ( int i = 0; i < n; ++i )
        scanf( "%s", final.text[i] );
        
    state tmp = clockwise( start );
    
    if ( tmp == final ) {
        printf( "1\n" );
    }else if ( (tmp=clockwise(tmp)) == final ) {
        printf( "2\n" );
    }else if ( (tmp=clockwise(tmp)) == final ) {
        printf( "3\n" );
    }else if ( reflect( start ) == final ) {
        printf( "4\n" );
    }else {
    
        tmp = clockwise( reflect( start ) );
    
        if ( tmp == final ) {
            printf( "5\n" );
        }else if ( (tmp=clockwise(tmp)) == final ) {
            printf( "5\n" );
        }else if ( (tmp=clockwise(tmp)) == final ) {
            printf( "5\n" );
        }else if ( start == final ) {
            printf( "6\n" );
        }else {
            printf( "7\n" );
        }
    
    }
        
    return 0;

}