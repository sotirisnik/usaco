/*
TASK: ariprog
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

#define MAXVAL 125000
#define MAXM 250

using namespace std;

bool exists[MAXVAL+1];
int A[MAXVAL+1];
set <int> s;
int n, m, cnt;

struct state {
    int val, step;
    state( int val, int step ) : val(val), step(step) { }
};

bool operator < (const state &a, const state &b ) {
    if ( a.step == b.step ) {
        return ( a.val < b.val );
    }
    return ( a.step < b.step );
}

vector <state> v;

bool f( int i, int b, int n ) {

    if ( i+n*b > MAXVAL ) {
        return ( false );
    }

    for ( int k = 1; k < n; ++k ) {
        if ( !exists[ i+k*b ] ) {
            return ( false );
        }
    }
    
    return ( true );

}

int main( ) {

    freopen( "ariprog.in", "r", stdin );
    freopen( "ariprog.out", "w", stdout );

    scanf( "%d %d", &n, &m );

    for ( int i = 0; i <= m; ++i ) {
        for ( int j = 0; j <= m; ++j ) {
            exists[ i*i + j*j ] = true;
            s.insert( i*i + j*j );
        }
    }
    
    for ( set<int>::iterator pos = s.begin(); pos != s.end(); ++pos ) {
        A[ cnt++ ] = *pos;
    }
    
    for ( int i = 0; i < cnt; ++i ) {
        for ( int j = i+1; j < cnt; ++j ) {        
            if ( f( A[i], A[j]-A[i], n ) ) {
                v.push_back( state( A[i], A[j]-A[i] ) );
            }
        }
    }
    
    if ( v.size() == 0 ) {
        printf( "NONE\n" );
    }else {
        
        sort( v.begin(), v.end() );
        
        for ( int i = 0; i < v.size(); ++i ) {
            printf( "%d %d\n", v[i].val, v[i].step );
        }
    
    }
    
    return 0;

}