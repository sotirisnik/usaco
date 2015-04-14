/*
TASK: combo
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100
#define MAXD 3

using namespace std;

struct state {
    int dial[MAXD];
};

int n, ans;
state john_combo, master_combo, tmp;

bool is_valid( state q1, state q2 ) {

    for ( int i = 0; i < MAXD; ++i ) {
        if ( abs( q1.dial[i] - q2.dial[i] ) > 2 && abs( q1.dial[i]+n-q2.dial[i] ) > 2 && abs( q1.dial[i]-n-q2.dial[i] ) > 2 ) {
            return ( false );
        }
    }
    
    return ( true );

}

void print( state tmp ) {

    for ( int i = 0; i < MAXD; ++i )
        printf( "%d ", tmp.dial[i] );
    printf( "\n" );

}

void f( int i ) {

    if ( i == MAXD ) {
        if ( is_valid( john_combo, tmp ) || is_valid( master_combo, tmp ) ) {
            ++ans;
        }
        return;
    }
    
    for ( int j = 1; j <= n; ++j ) {
        tmp.dial[i] = j;
        f( i + 1 );
    }

}

int main( ) {

    freopen( "combo.in", "r", stdin );
    freopen( "combo.out", "w", stdout );

    scanf( "%d", &n );
    
    for ( int i = 0; i < MAXD; ++i ) {
        scanf( "%d", &john_combo.dial[i] );
    }
    
    for ( int i = 0; i < MAXD; ++i ) {
        scanf( "%d", &master_combo.dial[i] );
    }
    
    f( 0 );
    
    printf( "%d\n", ans );
    
    return 0;

}