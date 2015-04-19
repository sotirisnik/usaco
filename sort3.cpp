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

int A[MAXN+1], cnt[MAXVAL], memo[MAXN+1][MAXN+1];
int n, cost;

struct state {
    int ones[3], twos[3], threes[3];
    int cost;
};

bool operator < (const state &a, const state &b ) {
    return ( a.cost > b.cost );
}

vector <int> vstate( state tmp ) {

    vector <int> ret;
    
    for ( int i = 0; i < 3; ++i )
        ret.push_back( tmp.ones[i] );
    for ( int i = 0; i < 3; ++i )
        ret.push_back( tmp.twos[i] );
    for ( int i = 0; i < 3; ++i )
        ret.push_back( tmp.threes[i] );
        
    return ( ret );
    
}

bool is_goal( state tmp ) {
    return ( tmp.ones[ONE] == cnt[ONE] && tmp.twos[TWO] == cnt[TWO] && tmp.threes[THREE] == cnt[THREE] );
}

void print( state tmp ) {

    printf( "%d %d %d| %d %d %d| %d %d %d\n", tmp.ones[ONE], tmp.ones[TWO], tmp.ones[THREE], tmp.twos[ONE], tmp.twos[TWO], tmp.twos[THREE], tmp.threes[ONE], tmp.threes[TWO], tmp.threes[THREE] );

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
            ++start.ones[ A[i]-1 ];
        }else if ( i <= cnt[ONE] + cnt[TWO] ) {
            ++start.twos[ A[i]-1 ];
        }else {
            ++start.threes[ A[i]-1 ];
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
        
        if ( top.ones[TWO] >= 1 && top.twos[ONE] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[TWO], top.twos[ONE] );
            
            tmp.ones[TWO] -= cost;
            tmp.ones[ONE] += cost;
            
            tmp.twos[ONE] -= cost;
            tmp.twos[TWO] += cost;
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
        if ( top.ones[TWO] >= 1 && top.twos[THREE] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[TWO], top.twos[THREE] );
            
            tmp.ones[TWO] -= cost;
            tmp.twos[THREE] -= cost;
            
            tmp.ones[THREE] += cost;
            tmp.twos[TWO] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }

        if ( top.ones[TWO] >= 1 && top.threes[ONE] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[TWO], top.threes[ONE] );
            
            tmp.ones[TWO] -= cost;
            tmp.threes[ONE] -= cost;
            
            tmp.ones[ONE] += cost;
            tmp.threes[TWO] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
        if ( top.ones[TWO] >= 1 && top.threes[TWO] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[TWO], top.threes[TWO] );
            
            tmp.ones[TWO] -= cost;
            tmp.threes[TWO] -= cost;
            
            tmp.ones[TWO] += cost;
            tmp.threes[TWO] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
        if ( top.ones[THREE] >= 1 && top.threes[ONE] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[THREE], top.threes[ONE] );
            
            tmp.ones[THREE] -= cost;
            tmp.threes[ONE] -= cost;
            
            tmp.ones[ONE] += cost;
            tmp.threes[THREE] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }

        if ( top.ones[THREE] >= 1 && top.threes[TWO] >= 1 ) {
            state tmp = top;
            
            cost = min( top.ones[THREE], top.threes[TWO] );
            
            tmp.ones[THREE] -= cost;
            tmp.threes[TWO] -= cost;
            
            tmp.ones[TWO] += cost;
            tmp.threes[THREE] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }

        if ( top.twos[ONE] >= 1 && top.threes[TWO] >= 1 ) {
            state tmp = top;
            
            cost = min( top.twos[ONE], top.threes[TWO] );
            
            tmp.twos[ONE] -= cost;
            tmp.twos[TWO] -= cost;
            
            tmp.twos[TWO] += cost;
            tmp.threes[ONE] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
        if ( top.twos[THREE] >= 1 && top.threes[ONE] >= 1 ) {
            state tmp = top;
            
            cost = min( top.twos[THREE], top.threes[ONE] );
            
            tmp.twos[THREE] -= cost;
            tmp.threes[ONE] -= cost;
            
            tmp.twos[ONE] += cost;
            tmp.threes[THREE] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
        if ( top.twos[THREE] >= 1 && top.threes[TWO] >= 1 ) {
            state tmp = top;
            
            cost = min( top.twos[THREE], top.threes[TWO] );
            
            tmp.twos[THREE] -= cost;
            tmp.threes[TWO] -= cost;
            
            tmp.twos[TWO] += cost;
            tmp.threes[THREE] += cost;
            
            tmp.cost += cost;
            
            if ( s.find( make_pair( vstate(tmp), tmp.cost ) ) == s.end( ) ) {
                q.push( tmp );
                s.insert( make_pair( vstate(tmp), tmp.cost ) );
            }
            
        }
        
    }

    return 0;

}