/*
TASK: money
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXV 25
#define MAXN 10000

using namespace std;

int A[MAXV+1];
long long memo[MAXV+1][MAXN+1];
int v, n;

long long best( int v, int n ) {

    if ( v == 0 ) {
        return ( n == 0 );
    }

    if ( memo[v][n] != -1 ) {
        return ( memo[v][n] );
    }
    
    memo[v][n] = best( v-1, n );
    
    if ( n >= A[v] ) {
        memo[v][n] += best( v, n-A[v] );
    }
    
    return ( memo[v][n] );

}

int main( ) {

    freopen( "money.in", "r", stdin );
    freopen( "money.out", "w", stdout );
    
    scanf( "%d %d", &v, &n );
    
    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    memset( memo, -1, sizeof( memo ) );
    
    printf( "%lld\n", best( v, n ) );

    return 0;

}