/*
TASK: milk3
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

struct state {
    vector <int> v;
};

set <int> ans;
set < vector<int> > visited;
stack <state> s;
state start;
int max_cap[3];

void print( state tmp ) {
    for ( int i = 0; i < tmp.v.size(); ++i ) {
        printf( "%d ", tmp.v[i] );
    }
    printf( "\n" );
}

int main( ) {

    freopen( "milk3.in", "r", stdin );
    freopen( "milk3.out", "w", stdout );

    scanf( "%d %d %d", &max_cap[0], &max_cap[1], &max_cap[2] );
    
    start.v.push_back( 0 );
    start.v.push_back( 0 );
    start.v.push_back( max_cap[2] );

    s.push( start );
    
    while ( !s.empty() ) {
        state top = s.top();
        s.pop();
        
        for ( int i = 0; i < top.v.size(); ++i ) {
            for ( int j = 0; j < top.v.size(); ++j ) {
                if ( i != j ) {
                    if ( top.v[i] >= max_cap[j]-top.v[j] ) {
                        state tmp = top;
                        tmp.v[j] += ( max_cap[j]-top.v[j] );
                        tmp.v[i] -= ( max_cap[j]-top.v[j] );
                        if ( visited.find( tmp.v ) == visited.end( ) ) {
                            s.push( tmp );
                            if ( tmp.v[0] == 0  ) {
                                ans.insert( tmp.v[2] );
                            }
                            visited.insert( tmp.v );
                        }
                    }else {
                        state tmp = top;
                        tmp.v[j] = min( max_cap[j], tmp.v[i]+tmp.v[j] );
                        tmp.v[i] = 0;
                        if ( visited.find( tmp.v ) == visited.end( ) ) {
                            s.push( tmp );
                            if ( tmp.v[0] == 0 ) {
                                ans.insert( tmp.v[2] );
                            }
                            visited.insert( tmp.v );
                        }
                    }
                    
                }
            }
        }
        
    }
    
    set <int>::iterator pos = ans.begin();
    
    printf( "%d", *pos );
    
    ++pos;
    
    for ( ; pos != ans.end(); ++pos ) {
        printf( " %d", *pos );
    }
    
    printf( "\n" );
    
    return 0;

}