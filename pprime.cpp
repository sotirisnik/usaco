/*
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 100000000
#define MAXL 10

using namespace std;

char text[MAXL];
int a, b;

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

void generate_pal( int i, int length, int mid  ) {

    if ( i == mid ) {
    
        for ( int j = length-1; j >= mid; --j ) {
            text[j] = text[length-1-j];
        }
        
        int tmp = atoi( text );

        if ( a <= tmp && tmp <= b && is_prime( tmp ) ) {
            printf( "%d\n", tmp );
        }
        
        return;
    }
    
    for ( int j = 0; j <= 9; ++j ) {
        if ( i == 0 && j == 0 ) {
            continue;
        }
        text[i] = '0'+j;
        generate_pal( i+1, length, mid );
    }

}

int main( ) {

    freopen( "pprime.in", "r", stdin );
    freopen( "pprime.out", "w", stdout );

    scanf( "%d %d", &a, &b );
    
    int length_a = log10( a ) + 1;
    int length_b = log10( b ) + 1;
    
    for ( int i = length_a; i <= length_b; ++i ) {
        int mid = i/2;
        
        if ( i % 2 == 1 ) {
            ++mid;
        }
        
        generate_pal( 0, i, mid );
    }
    
    return 0;

}