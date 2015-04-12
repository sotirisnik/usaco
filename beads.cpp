/*
TASK: beads
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXN 350

int n, ans;
char text[MAXN+1];

int go_right( int i ) {

    int cnt = 1;      
    int j = (i+2) % n;
    
    while ( (i+1)%n != j ) {
        if ( text[j] == 'w' ) {
            ++cnt;
        }else if ( text[j] != text[(i+1)%n] ) {
            break;
        }else {
            ++cnt;
        }
        ++j;            
        j %= n;
    }
        
    return ( cnt );
        
}

int go_left( int i ) {

    int j = (i-1);
    if ( j < 0 ) {
        j = n-1;
    }
    
    int cnt = 1;

    while ( i != j ) {
        if ( text[j] == 'w' ) {
            ++cnt;
        }else if ( text[j] != text[i] ) {
            break;
        }else {
            ++cnt;
        }
        --j;
        if ( j < 0 ) {
            j = n -1;
        }
    }
    
    return ( cnt );

}

int cost( int i ) {

    int ret = 0;

    int left_ret = 0, right_ret = 0;
    
    if ( text[i] == 'w' ) {

        text[i] = 'r';
        right_ret = max( right_ret, go_right( i ) );
        left_ret = max( left_ret, go_left( i ) );

        text[i] = 'b';
        right_ret = max( right_ret, go_right( i ) );
        left_ret = max( left_ret, go_left( i ) );
    
        text[i] = 'w';
        
    }else {
        
        right_ret = go_right( i );
        left_ret = go_left( i );
        
    }
    
    return ( left_ret + right_ret );
    
}

int main( ) {

    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    
    scanf ( "%d %s", &n, text );
    
    for ( int i = 0; i < n; ++i ) {
        
        int tmp = cost( i );
        
        if ( i == 0 ) {
            ans = tmp;
        }else {
            ans = max( ans, tmp );
        }
    }
    
    printf( "%d\n", min( n, ans ) );

    return 0;
    
}
