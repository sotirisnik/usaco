/*
TASK: frac1
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
    int num, denom;
    state( int num, int denom ) : num(num), denom(denom) { }
};

bool operator<( const state &a, const state &b ) {
    if ( a.num*b.denom == b.num * a.denom ) {
        return ( a.denom < b.denom );
    }
    return ( a.num*b.denom < b.num * a.denom );
}

vector <state> v;
int n;

int main( ) {

    freopen( "frac1.in", "r", stdin );
    freopen( "frac1.out", "w", stdout );
    
    scanf( "%d", &n );
    
    for ( int i = 0; i <= n; ++i ) {
        for ( int j = i; j <= n; ++j ) {
            if ( j == 0 ) {
                continue;
            }
            v.push_back( state(i,j) );
        }
    }
    
    sort( v.begin(), v.end() );
    
    printf( "%d/%d\n", v[0].num, v[0].denom );
    
    for ( int i = 1; i < v.size(); ++i ) {
        if ( v[i].num * v[i-1].denom != v[i-1].num * v[i].denom ) {
            printf( "%d/%d\n", v[i].num, v[i].denom );
        }
    }

    return 0;

}