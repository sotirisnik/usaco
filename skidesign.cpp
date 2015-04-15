/*
TASK: skidesign
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 1000
#define MAXL 100

using namespace std;

int A[MAXN];
int n, ans;

int cost( int a, int b ) {

    int ret = 0;
    
    for ( int k = 0; k < n; ++k ) {
        if ( A[k] < a ) {
            ret += ( a-A[k] ) * ( a-A[k] );
        }else if ( A[k] > b ) {
            ret += ( A[k]-b ) * ( A[k]-b );
        }
    }
    
    return ( ret );
        
}

int main( ) {

    freopen( "skidesign.in", "r", stdin );
    freopen( "skidesign.out", "w", stdout );

    scanf( "%d", &n );
    
    for ( int i = 0; i < n; ++i ) {
        scanf( "%d", &A[i] );
    }
    
    sort( A, A+n );
    
    ans = 0;

    for ( int i = A[0]; i <= A[n-1]; ++i ) {
        for ( int j = A[0]; j <= A[n-1]; ++j ) {
        
            if ( (-j+A[n-1]) - (A[0]+i) > 17 ) {
                continue;
            }
            
            if ( A[0]+i > -j+A[n-1] ) {
                continue;
            }
            
            int tmp = cost( min( A[0]+i, 100 ), max( 0, -j+A[n-1] ) );
            
            if ( ans == 0 || ans > tmp ) {
                ans = tmp;
            }
            
        }
    }
    
    printf( "%d\n", ans );
    
    return 0;

}