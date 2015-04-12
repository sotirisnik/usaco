/*
TASK: ride
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXL 7
#define MODN 47

using namespace std;

char comet[MAXL], group[MAXL];

int prod( char *text ) {

    int ret = 0;
    
    for ( int i = 0; text[i] != '\0'; ++i ) {
        if ( i == 0 ) {
            ret = text[i]-'A'+1;
            ret %= MODN;
        }else {
            ret *= ( text[i]-'A'+1 );
            ret %= MODN;
        }
    }
    
    return ( ret );

}

int main( ) {

    freopen( "ride.in", "r", stdin );
    freopen( "ride.out", "w", stdout );
    
    scanf( "%s %s", comet, group );

    if ( prod( comet ) == prod( group ) ) {
        printf( "GO\n" );
    }else {
        printf( "STAY\n" );
    }
    
    return 0;

}