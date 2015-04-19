/*
TASK: hamming
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 64
#define MAXB 8

using namespace std;

int n, b, d;
bool found;
int A[MAXN];

int dist( int q1, int q2 ) {

    int ret = 0;

    for ( int i = 0; i < b; ++i ) {
        if ( q1 & (1<<i) ) {
            if ( !( q2 & (1<<i) ) ) {
                ++ret;
            }
        }else {
            if ( q2 & (1<<i) ) {
                ++ret;
            }
        }
    }
    
    return ( ret );

}

void f( int i ) {

    if ( found ) {
        return;
    }

    if ( i == n ) {
    
        printf( "%d", A[0] );
        bool start = false;
        
        for ( int j = 1; j < n; ++j ) {
            if ( start == false ) {
                putchar( ' ' );
            }
            start = false;
            printf( "%d", A[j] );
            if ( (j+1) % 10 == 0 ) {
                start = true;
                putchar( '\n' );
            }
        }
        
        if ( start == false ) {
            printf( "\n" );
        }
        
        found = true;
        return;
    }
    
    if ( i == 0 ) {
        for ( int j = 0; j <= (1<<b); ++j ) {
            A[i] = j;
            f( i + 1 );
        }
        return;
    }
    
    for ( int pos = 1; pos <= (1<<b) && !found; ++pos ) {
    
        bool is_candidate = true;
    
        for ( int k = 0; k < i; ++k ) {
            if ( pos == A[k] || dist( A[k], pos ) < d ) {
                is_candidate = false;
                break;
            }
        }
    
        if ( is_candidate ) {
            A[i] = pos;
            f( i+1 );
        }
        
    }
    
}

int main( ) {

    freopen( "hamming.in", "r", stdin );
    freopen( "hamming.out", "w", stdout );
    
    scanf( "%d %d %d", &n, &b, &d );

    f(0);
    
    return 0;

}