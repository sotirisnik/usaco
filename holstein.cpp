/*
TASK: holstein
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXV 25
#define MAXG 15

using namespace std;

int daily_v[MAXV], A[MAXG][MAXV], tmp[MAXV];
int v, g, cnt, ans;

int main( ) {

    freopen( "holstein.in", "r", stdin );
    freopen( "holstein.out", "w", stdout );

    scanf( "%d", &v );
    
    for ( int i = 0; i < v; ++i ) {
        scanf( "%d", &daily_v[i] );
    }
    
    scanf( "%d", &g );
    
    for ( int i = 0; i < g; ++i ) {
        for ( int j = 0; j < v; ++j ) {
            scanf( "%d", &A[i][j] );
        }
    }
    
    cnt = -1;
    
    for ( int i = 0; i <= (1<<g); ++i ) {
    
        for ( int j = 0; j < v; ++j )
            tmp[j] = 0;
    
        for ( int j = 0; j < g; ++j ) {
            if ( i & (1<<j) ) {
                for ( int k = 0; k < v; ++k ) {
                    tmp[k] += A[j][k];
                }
            }
        }
        
        bool is_candidate = true;
        
        for ( int j = 0; j < v; ++j ) {
            if ( tmp[j] < daily_v[j] ) {
                is_candidate = false;
                break;
            }
        }
        
        if ( is_candidate ) {
            
            int tmp_cnt = 0;
            
            for ( int j = 0; j < g; ++j ) {
                if ( i & (1<<j) ) {
                    ++tmp_cnt;
                }
            }
            
            if ( cnt == -1 || cnt > tmp_cnt ) {
                ans = i;
                cnt = tmp_cnt;
            }
            
        }
    
    }
    
    printf( "%d", cnt );
    
    for ( int j = 0; j < g; ++j ) {
        if ( ans & (1<<j) ) {
            printf( " %d", j+1 );
        }
    }
    
    printf( "\n" );

    return 0;

}