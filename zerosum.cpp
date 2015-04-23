/*
TASK: zerosum
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <algorithm>

#define MAXN 9
#define OFFSET 50

using namespace std;

int sign[MAXN+1];
vector <string> sol;
int n;

int check_sum( ) {

    int ret = 0;
    
    int val = 1;

    int i = 1;
    
    while ( sign[i+1] == 0 && i+1 <= n ) {
        val *= 10;
        val += i+1;
        ++i;
    }
    
    ++i;
    
    stack <int> s;
    
    s.push( val );
    
    bool pos = true;
    
    for ( ; i <= n; ++i ) {
        if ( sign[i] == -1 ) {
            pos = false;
            val = i;
            while ( sign[i+1] == 0 && i+1 <= n ) {
                val *= 10;
                val += i+1;
                ++i;
            }
            val = -val;
        }else if ( sign[i] == 1 ) {
            pos = true;
            val = i;
            while ( sign[i+1] == 0 && i+1 <= n ) {
                val *= 10;
                val += i+1;
                ++i;
            }
        }
        
        s.push( val );
        
    }
    
    while ( !s.empty() ) {
        
        int top = s.top();
        s.pop();
        
        ret += top;
        
    }
    
    return ( ret );

}

void f( int i ) {

    if ( i == n+1 ) {
        if ( check_sum( ) == 0 ) {
            string tmp = "1";
            for ( int j = 2; j <= n; ++j ) {
                if ( sign[j] == 1 ) {
                    tmp += "+";
                }else if ( sign[j] == 0 ) {
                    tmp += " ";
                }else {
                    tmp += "-";
                }
                tmp += '0'+j;
            }
            sol.push_back( tmp );
        }
        return;
    }
    
    sign[i] = 1;
    f( i+1 );
    
    if ( i > 1 ) {
    
        sign[i] = -1;
        f( i+1 );
        
        sign[i] = 0;
        f( i+1 );

    }
    
}

int main( ) {

    freopen( "zerosum.in", "r", stdin );
    freopen( "zerosum.out", "w", stdout );

    scanf( "%d", &n );

    f( 1 );
    
    sort( sol.begin(), sol.end() );
    
    for ( int i = 0; i < sol.size(); ++i ) {
        printf( "%s\n", sol[i].c_str() );
    }
    
    return 0;

}