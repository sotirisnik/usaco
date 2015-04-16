/*
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 1000

using namespace std;

int A[MAXN][MAXN], memo[MAXN][MAXN];
int n;

int best ( int x , int y ) {

    if ( x == n-1 ) {
        return ( A[x][y] );
    }
    
    if ( memo[x][y] != -1 ) {
        return ( memo[x][y] );
    }
    
    int c1 = best ( x+1 , y );
    int c2 = best ( x+1 , y+1 );
    int Best = A[x][y] + max ( c1 , c2 );

    memo[x][y] = Best;

    return ( Best );

}

int main ( ) {

    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);

    scanf ( "%d" , &n );

    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j <= i; ++j )
            scanf ( "%d" , &A[i][j] );

    memset( memo, -1, sizeof( memo ) );
            
    printf ( "%d\n" , best ( 0 , 0 ) );

    return 0;

}
