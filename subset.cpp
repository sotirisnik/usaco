/*
TASK: subset
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 39
#define MAXVAL 780

using namespace std;

long long memo[MAXN+1][MAXVAL+1];
int n;

long long best( int i, int c ) {

    if ( i == n+1 ) {
        return ( 4*c == n*(n+1) );
    }
    
    if ( memo[i][c] != -1 ) {
        return ( memo[i][c] );
    }
    
    memo[i][c] = best( i+1, c ) + best( i+1, c+i );
    
    return ( memo[i][c] );

}

int main( ) {

    freopen( "subset.in", "r", stdin );
    freopen( "subset.out", "w", stdout );
    
    scanf( "%d", &n );

    memset( memo, -1, sizeof( memo ) );
    
    printf( "%lld\n", best( 1, 0 ) / 2 );
    
    return 0;

}