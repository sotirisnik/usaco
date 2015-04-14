/*
TASK: crypt1
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 100
#define MAXS 5
#define MAXD 10

using namespace std;

int n, x, cnt, ans;
int A[MAXN], B[MAXS];
bool exists[MAXD];

bool is_prime( int i ) {

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

bool is_valid( int tmp ) {

    while ( tmp > 0 ) {
        if ( exists[ tmp % 10 ] == false ) {
            return ( false );
        }
        tmp /= 10;
    }
    
    return ( true );

}

void f( int i ) {

    if ( i == 5 ) {
        //de*abc
        int abc = B[0]*100 + B[1]*10 + B[2];
        int de = B[3]*10 + B[4];
        
        int p1 = B[4] * abc;
        int p2 = B[3] * abc;
        
        if ( p1 > 99 && p1 < 1000 && p2 > 99 && p2 < 1000 && is_valid( p1 ) && is_valid( p2 ) ) {
            
            if ( is_valid( de * abc ) ) {
                ++ans;
            }
            
        }
        
        return;
    }
    
    for ( int j = 0; j < n; ++j ) {
        B[i] = A[j];
        f( i + 1 );
    }

}

int main( ) {

    freopen( "crypt1.in", "r", stdin );
    freopen( "crypt1.out", "w", stdout );

    scanf( "%d", &n );

    for ( int i = 0; i < n; ++i ) {
        scanf( "%d", &A[i] );
        exists[ A[i] ] = true;
    }
    
    f( 0 );
    
    printf( "%d\n", ans );
    
    return 0;

}