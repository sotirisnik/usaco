/*
TASK: milk2
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAXN 5000

using namespace std;

struct state {
    int from, to;
    state( ) { }
    state( int from, int to ) : from( from ), to( to ) { }
};

bool operator <( const state &a, const state &b ) {
    return ( a.from < b.from );
}

vector <state> F;
int n, from, to, cont, idle;

int main( ) {

    freopen( "milk2.in", "r", stdin );
    freopen( "milk2.out", "w", stdout );

    scanf( "%d", &n );
    
    for ( int i = 0; i < n; ++i ) {
        scanf( "%d %d", &from, &to );
        F.push_back( state( from, to ) );
    }
    
    for ( int j = 0; j < n; ++j ) {
    
        vector <state> tmp_F;
        
        for ( int i = 1; i < F.size(); ++i ) {
            if ( (F[i].from >= F[0].from && F[i].from <= F[0].to) ) {
                F[0].to = max( F[0].to, F[i].to );
            }else {
                tmp_F.push_back( F[i] );
            }
        }
        
        tmp_F.push_back( F[0] );
    
        F = tmp_F;
    
    }
    
    sort( F.begin(), F.end() );
    
    cont = F[0].to - F[0].from;
    
    for ( int i = 1; i < F.size(); ++i ) {
        cont = max( cont, F[i].to - F[i].from );
        idle = max( idle, F[i].from - F[i-1].to );
    }
    
    printf( "%d %d\n", cont, idle );
    
    return 0;

}