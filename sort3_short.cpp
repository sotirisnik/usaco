/*
TASK: sort3
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <algorithm>

#define MAXN 1000
#define MAXVAL 3
#define ONE 0
#define TWO 1
#define THREE 2

using namespace std;

int A[MAXN+1], cnt[MAXVAL];
int n, cost;

struct state {
    int cnt[MAXVAL][MAXVAL];
    int cost;
};

bool operator < (const state &a, const state &b ) {
    return ( a.cost > b.cost );
}

vector <int> vstate( state tmp ) {

    vector <int> ret;
    
    for ( int i = 0; i < MAXVAL; ++i ) {
        for ( int j = 0; j < MAXVAL; ++j ) {
            ret.push_back( tmp.cnt[i][j] );
        }
    }
        
    return ( ret );
    
}

bool is_goal( state tmp ) {
    for ( int i = 0; i < MAXVAL; ++i ) {
        if ( tmp.cnt[i][i] != cnt[i] ) {
            return ( false );
        }
    }
    return ( true );
}

priority_queue <state> q;
set < pair< vector<int>, int > > s;
state start;

int main( ) {

    freopen( "sort3.in", "r", stdin );
    freopen( "sort3.out", "w", stdout );

    scanf( "%d", &n );
    
    for ( int i = 1; i <= n; ++i ) {
        scanf( "%d", &A[i] );
        ++cnt[ A[i]-1 ];
    }
    
    for ( int i = 1; i <= n; ++i ) {
        if ( i <= cnt[ONE] ) {
            ++start.cnt[ONE][ A[i]-1 ];
        }else if ( i <= cnt[ONE] + cnt[TWO] ) {
            ++start.cnt[TWO][ A[i]-1 ];
        }else {
            ++start.cnt[THREE][ A[i]-1 ];
        }
    }
    
    q.push( start );
    
    while ( !q.empty() ) {
    
        state top = q.top();
        q.pop();
        
        if ( is_goal( top ) ) {
            printf( "%d\n", top.cost );
            break;
        }

        for ( int i = 0; i < MAXVAL; ++i ) {
            for ( int j = i+1; j < MAXVAL; ++j ) {
                for ( int k = 0; k < MAXVAL; ++k ) {
                    if ( i == k ) {
                        continue;
                    }
                    for ( int z = 0; z < MAXVAL; ++z ) {
                        if ( j == z ) {
                            continue;
                        }
                        if ( top.cnt[i][k] >= 1 && top.cnt[j][z] >= 1 ) {
                            state tmp = top;

                            cost = min( top.cnt[i][k], top.cnt[j][z] );

                            tmp.cnt[i][k] -= cost;
                            tmp.cnt[j][z] -= cost;
                            
                            tmp.cnt[i][z] += cost;
                            tmp.cnt[j][k] += cost;
                            tmp.cost += cost;

                            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                                q.push( tmp );
                                s.insert( make_pair( vstate(tmp), tmp.cost ) );
                            }

                        }
                    }
                
                }
            }
        }
        
    }

    return 0;

}