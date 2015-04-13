/*
TASK: barn1
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXC 200
#define MAXM 50
#define INF 999999999

using namespace std;

int M, S, C, ans;
int A[MAXC];
int memo[MAXC][MAXM];

int best( int i, int m ) {

    if ( m < 0 ) {
        return ( INF );
    }
    
    if ( i < 0 ) {
        return 0;
    }
    
    if ( memo[i][m] != -1 ) {
        return ( memo[i][m] );
    }
    
    int Best = INF;
    
    for ( int j = 0; j <= i; ++j ) 
        Best = min( Best, A[i]-A[j]+1+best( j-1, m-1 ) );
        
    memo[i][m] = Best;
    
    return ( Best );

}

int main( ) {

    freopen( "barn1.in", "r", stdin );
    freopen( "barn1.out", "w", stdout );

    scanf( "%d %d %d", &M, &S, &C );
    
    for ( int i = 0; i < C; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    sort( A, A+C );
    
    memset( memo, -1, sizeof( memo ) );
    
    printf( "%d\n", best( C-1, M ) );
    
    return 0;

}