/*
TASK: concom
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 100
#define MAXVAL 100

using namespace std;

bool adj[MAXN][MAXN];
int adj_owns[MAXN][MAXN];
int n, from, to, owns, tmp;
bool change;

int owns_company( int A, int B ) {

    int ret = 0;

    for ( int i = 0; i < MAXN; ++i ) {
        if ( i != A && adj[A][i] && adj_owns[A][i] > 50 ) {
            if ( adj[i][B] ) {
                ret += adj_owns[i][B];
                ret = min( ret, MAXVAL );
            }
        }
    }
    
    ret += adj_owns[A][B];
    ret = min( ret, MAXVAL );
    
    return ( ret );

}

int main( ) {

    freopen( "concom.in", "r", stdin );
    freopen( "concom.out", "w", stdout );

    scanf( "%d", &n );
    
    for ( int i = 0; i < n; ++i ) {
        scanf( "%d %d %d", &from, &to, &owns );
        --from;
        --to;
        adj[from][to] = 1;
        adj_owns[from][to] = owns;
    }
    
    while ( true ) {
    
        change = false;
        
        for ( int i = 0; i < MAXN; ++i )
            for ( int j = 0; j < MAXN; ++j ) {
                if ( adj_owns[i][j] > 50 ) {
                    continue;
                }
                if ( i != j && ( tmp = owns_company( i, j ) ) > 50 ) {
                    adj[i][j] = 1;
                    adj_owns[i][j] = tmp;
                    change = true;
                }
            }
            
        if ( !change ) {
            break;
        }
        
    }

    for ( int i = 0; i < MAXN; ++i )
        for ( int j = 0; j < MAXN; ++j ) {
            if ( i != j && adj_owns[i][j] > 50 ) {
                printf( "%d %d\n", i+1, j+1 );
            }
        }
    
    return 0;

}