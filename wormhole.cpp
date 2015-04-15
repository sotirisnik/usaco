/*
TASK: wormhole
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>

#define MAXN 12

using namespace std;

struct state {
    int x, y;
};

state P[MAXN];
int A[MAXN], adj[MAXN], right_next[MAXN];
bool avail[MAXN], visited[MAXN];
int n, ans;

void build_next( ) {

    for ( int i = 0; i < n; ++i )
        right_next[i] = -1;

    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j ) {
            if  ( i != j ) {
                if ( P[i].y == P[j].y && P[i].x < P[j].x ) {
                    if ( right_next[i] == -1 || P[j].x < P[ right_next[i] ].x ) {
                        right_next[i] = j;   
                    }
                }
            }
        }
    
}

int find_next( int i ) {
    return ( right_next[i] );
}

bool is_cycle( int start ) {

    for ( int i = 0; i < n; ++i ) {
        visited[i] = false;
    }

    int idx = start;
    
    while ( true ) {
    
        idx = find_next( idx );
        
        if ( idx == -1 ) {
            return ( false );
        }
        
        if ( visited[ idx ] ) {
            break;
        }
        
        visited[ idx ] = true;
        
        idx = adj[idx];
        
    }
    
    return ( idx != -1 );
    
}

void f( int i ) {

    if ( i >= n ) {
    
        for ( int j = 0; j < n; j += 2 ) {
            adj[ A[j] ] = A[j+1];
            adj[ A[j+1] ] = A[j];
        }
        
        build_next( );
        
        for ( int j = 0; j < n; ++j ) {
            if ( is_cycle( j ) ) {
                ++ans;
                return;
            }
        }
        
        return;
    }
    
    int k = 0;
    
    for ( ; k < n; ++k ) {
        if ( avail[k] ) {
            break;
        }
    }
    
    if ( k == n ) {
        return;
    }
    
    avail[k] = false;
    
    A[i] = k;
    
    for ( int j = k+1; j < n; ++j ) {
        if ( avail[j] ) {
            A[i+1] = j;
            avail[j] = false;
            f( i + 2 );
            avail[j] =  true;
        }
    }
    
    avail[k] = true;
}

int main( ) {

    freopen( "wormhole.in", "r", stdin );
    freopen( "wormhole.out", "w", stdout );

    scanf( "%d", &n );

    for ( int i = 0; i < n; ++i ) {
        scanf( "%d %d", &P[i].x, &P[i].y );
    }
    
    for ( int i = 0; i < n; ++i )
        avail[i] = true;
        
    f( 0 );
    
    printf( "%d\n", ans );
    
    return 0;

}