/*
TASK: prefix
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

#define MAXP 200
#define MAXS 200000

using namespace std;

string primitives[MAXP+1];
string text, tmp;
int memo[MAXS+1];
int cnt, n;

bool check( int prim_idx, int text_idx ) {

    for ( int i = 0; i < primitives[prim_idx].size(); ++i ) {
        if ( primitives[prim_idx][i] != text[ text_idx+i ] ) {
            return ( false );
        }
    }
            
    return ( true );

}

int best( int i ) {
    
    if ( memo[i] != -1 ) {
        return ( memo[i] );
    }
    
    int Best = i;
    
    for ( int j = 0; j < cnt; ++j ) {
        if ( primitives[j].size() + i <= n ) {
            if ( check( j, i ) ) {
                Best = max( Best, best( i + primitives[j].size() ) );
            }
        }
    }
    
    memo[i] = Best;
    
    return ( Best );

}

int main( ) {

    freopen( "prefix.in", "r", stdin );
    freopen( "prefix.out", "w", stdout );

    while ( true ) {
        cin >> primitives[cnt];
        if ( primitives[cnt][0] == '.' ) {
            break;
        }
        ++cnt;
    }
    
    while ( cin >> tmp ) {
        text += tmp;
    }
    
    n = text.size();
    
    memset( memo, -1, sizeof( memo ) );
    
    printf( "%d\n", best( 0 ) );
    
    return 0;

}