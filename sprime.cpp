/*
TASK: sprime
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n;

bool is_prime( int x ) {

    if ( x < 2 ) {
        return ( false );
    }
    
    if ( x != 2 && x % 2 == 0 ) {
        return ( false );
    }

    int sqrt_x = sqrt(x)+1;
    
    for ( int i = 3; i < sqrt_x; i += 2 )
        if ( x % i == 0 )
            return ( false );
    
    return ( true );

}

void f( int x, int n ) {

    if ( is_prime( x ) ) {
    
        if ( n == 1 ) {
            printf( "%d\n", x );
            return;
        }
        
        for ( int i = 0; i < 10; ++i ) {
            f( x*10 + i, n-1 );
        }
    
    }

}

int main( ) {

    freopen( "sprime.in", "r", stdin );
    freopen( "sprime.out", "w", stdout );

    scanf( "%d", &n );

    f( 2, n );
    f( 3, n );
    f( 5, n );
    f( 7, n );
    
    return 0;

}