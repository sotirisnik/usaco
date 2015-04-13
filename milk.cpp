/*
TASK: milk
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 5000

using namespace std;

struct state {
    int unit, cpu;
};

bool operator < ( const state &a, const state &b ) {
    
    return ( a.cpu < b.cpu );
    
}

state farmer[MAXN];

int n, m, ans;

int main( ) {

    freopen( "milk.in", "r", stdin );
    freopen( "milk.out", "w", stdout );

    scanf( "%d %d", &n, &m );

    for ( int i = 0; i < m; ++i ) {
        scanf( "%d %d", &farmer[i].cpu, &farmer[i].unit );
    }
    
    sort( farmer, farmer+m );
    
    for ( int i = 0; i < m; ++i ) {
        
        int unit_can_take = min( n, farmer[i].unit );
        ans += ( unit_can_take * farmer[i].cpu );
        
        n -= unit_can_take;
        
        if ( n == 0 ) {
            break;
        }
        
    }
    
    printf( "%d\n", ans );
    
    return 0;

}