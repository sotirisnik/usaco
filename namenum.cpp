/*
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 5000
#define MAXL 13

using namespace std;

struct state {
    char name[MAXL];
};

char moves[10][10] = {
    { },
    { },
    { 'A', 'B', 'C' },
    { 'D', 'E', 'F' },
    { 'G', 'H', 'I' },
    { 'J', 'K', 'L' },
    { 'M', 'N', 'O' },
    { 'P', 'R', 'S' },
    { 'T', 'U', 'V' },
    { 'W', 'X', 'Y' }
};

char serial[ MAXL ], ans[ MAXL ];
state dict[ MAXN ];
int n, cnt;
bool found;

bool is_valid( char name[] ) {

    int lo = 0;
    int hi = cnt-1;

    while ( lo <= hi ) {
    
        int mid = ( lo + hi ) / 2;
    
        int cmp = strcmp( name, dict[mid].name );
        
        if ( cmp == 0 ) {
            return ( true );
        }else if ( cmp < 0 ) {
            hi = mid-1;
        }else {
            lo = mid+1;
        }
    
    }
    
    return ( false );
    
}

void solve( int i ) {

    if ( i == n ) {
        if ( is_valid( ans ) ) {
            printf( "%s\n", ans );
            found = true;
        }
        return;
    }
    
    for ( int j = 0; j < 3; ++j ) {
        ans[ i ] = moves[ serial[i]-'0' ][ j ];
        solve( i + 1 );
    }
    
}

int main( ) {

    freopen( "namenum.in", "r", stdin );
    freopen( "namenum.out", "w", stdout );

    FILE *fin = fopen( "dict.txt", "r" );
    
    while ( fscanf( fin, "%s", dict[ cnt ].name ) != EOF ) {
        ++cnt;
    }
    
    fclose( fin );

    scanf( "%s", serial );
    
    n = strlen( serial );
    
    found = false;
    
    solve( 0 );
    
    if ( !found ) {
        printf( "NONE\n" );
    }
    
    return 0;
    
}