/*
TASK: nocows
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <algorithm>

#define MAXN 200
#define MAXK 100
#define MODN 9901

using namespace std;

int memo[MAXN+1][MAXK+1];
int n, k;

int best( int nodes, int height ) {

    if ( height == 1 ) {
        return ( nodes == 1 );
    }
    
    if ( memo[nodes][height] != -1 ) {
        return ( memo[nodes][height] );
    }
   
    int Best = 0;
    
    for ( int j = 1; j <= nodes-2; ++j ) {
    
        for ( int k = 1; j >= k && nodes-j-1 >= height-1 && k < height-1; ++k ) {
            Best += 2 * best( j, k ) * best( nodes-j-1, height-1 );
            Best %= MODN;
        }
        
        Best += best( j, height-1 ) * best( nodes-j-1, height-1 );
        Best %= MODN;
        
    }
    
    memo[nodes][height] = Best;
   
    return ( Best );
    
}

int main( ) {

    freopen( "nocows.in", "r", stdin );
    freopen( "nocows.out", "w", stdout );

    scanf( "%d %d", &n, &k );
    
    memset( memo, -1, sizeof( memo ) );
            
    printf( "%d\n", best( n, k ) );
    
    return 0;

}