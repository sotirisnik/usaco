/*
TASK: runround
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXL 20
#define MAXD 9

using namespace std;

unsigned long long n, length, cnt;
char text[MAXL+1];
bool seen[MAXD+1];
bool all_different;

int count_digits( unsigned long long tmp ) {

    int ret = 0;

    while ( tmp > 0 ) {
        ++ret;
        tmp /= 10;
    }
    
    return ( ret );

}

void to_text( unsigned long long tmp ) {

    length = count_digits( tmp );
    
    cnt = length - 1;
    
    while ( tmp > 0 ) {
        text[cnt--] = '0'+( tmp % 10 );
        tmp /= 10;
    }

}

bool is_runround( int i ) {

    if ( seen[i] ) {
        if ( i == 0 ) {
            for ( int j = 0; j < length; ++j )
                if ( !seen[j] ) {
                    return ( false );
                }
            return ( true );
        }
        return ( false );
    }
    
    seen[i] = true;
    
    return is_runround( ( i + text[i]-'0' ) % length );
    
}

int main( ) {

    freopen( "runround.in", "r", stdin );
    freopen( "runround.out", "w", stdout );

    scanf( "%llu", &n );
    
    while ( true ) {
    
        ++n;
        
        to_text( n );
        
        for ( int i = 0; i <= MAXD; ++i ) {
            seen[i] = false;
        }
        
        all_different = true;
        
        for ( int i = 0; i < length; ++i ) {
            if ( !seen[ text[i]-'0' ] ) {
                seen[ text[i]-'0' ] = true;
            }else {
                all_different = false;
                break;
            }
        }
        
        if ( !all_different || seen[0] ) {
            continue;
        }
        
        for ( int i = 0; i < length; ++i ) {
            seen[i] = false;
        }
        
        if ( is_runround( 0 ) ) {
            printf( "%llu\n", n );
            break;
        }
    
    }
    
    return 0;

}