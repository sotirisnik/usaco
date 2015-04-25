/*
TASK: ttwo
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

#define MAXN 11
#define MODN 4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

struct state {
    int cow_x, cow_y, john_x, john_y, cow_dir, john_dir, cost;
};

vector <int> vstate( state tmp ) {

    vector <int> ret;
    
    ret.push_back( tmp.cow_x );
    ret.push_back( tmp.cow_y );
    ret.push_back( tmp.cow_dir );
    ret.push_back( tmp.john_x );
    ret.push_back( tmp.john_y );
    ret.push_back( tmp.john_dir );
    
    return ( ret );

}

queue <state> q;
set < vector<int> > s;
char maze[MAXN+1][MAXN+1];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n;
bool found;

bool valid( int x, int y ) {
    return ( x >= 0 && y >= 0 && x <= MAXN && y <= MAXN );
}

bool check( state tmp ) {
    return ( tmp.cow_x == tmp.john_x && tmp.cow_y == tmp.john_y );
}

int main( ) {

    freopen( "ttwo.in", "r", stdin );
    freopen( "ttwo.out", "w", stdout );

    for ( int i = 1; i < MAXN; ++i ) {
        for ( int j = 1; j < MAXN; ++j ) {
            scanf( " %c", &maze[i][j] );
        }
    }
    
    for ( int i = 0; i <= MAXN; ++i ) {
        maze[0][i] = '*';
        maze[MAXN][i] = '*';
        maze[i][0] = '*';
        maze[i][MAXN] = '*';
    }

    state start;
    
    for ( int i = 1; i <= MAXN; ++i )
        for ( int j = 1; j <= MAXN; ++j ) {
            if ( maze[i][j] == 'F' ) {
                start.john_x = i;
                start.john_y = j;
                start.john_dir = NORTH;
                maze[i][j] = '.';
            }else if ( maze[i][j] == 'C' ) {
                start.cow_x = i;
                start.cow_y = j;
                start.cow_dir = NORTH;
                maze[i][j] = '.';
            }
        }
        
    start.cost = 0;
    
    q.push( start );
    s.insert( vstate( start ) );
    
    if ( check( start ) ) {
        printf( "0\n" );
        return 0;
    }
    
    while ( !q.empty() ) {
        
        state top = q.front();
        q.pop();
        
        ++top.cost;
       
        state tmp = top;
       
        if ( valid( top.cow_x + dx[ top.cow_dir ], top.cow_y + dy[ top.cow_dir ] ) ) {
                
            if ( maze[ top.cow_x + dx[ top.cow_dir ] ][ top.cow_y + dy[ top.cow_dir ] ] == '*' ) {
                tmp.cow_dir += 1;
                tmp.cow_dir %= MODN;
            }else {
                tmp.cow_x += dx[ tmp.cow_dir ];
                tmp.cow_y += dy[ tmp.cow_dir ];
            }
                
        }else {
            tmp.cow_dir += 1;
            tmp.cow_dir %= MODN;
        }
        
        if ( valid( top.john_x + dx[ top.john_dir ], top.john_y + dy[ top.john_dir ] ) ) {
            
            if ( maze[ top.john_x + dx[ top.john_dir ] ][ top.john_y + dy[ top.john_dir ] ] == '*' ) {
                tmp.john_dir += 1;
                tmp.john_dir %= MODN;
            }else {
                tmp.john_x += dx[ tmp.john_dir ];
                tmp.john_y += dy[ tmp.john_dir ];
            }

        }else {
            tmp.john_dir += 1;
            tmp.john_dir %= MODN;
        }
        
        if ( s.find( vstate( tmp ) ) == s.end( ) ) {
        
            q.push( tmp );
            s.insert( vstate( tmp ) );
            
            if ( check( tmp ) ) {
                printf( "%d\n", tmp.cost );
                found = true;
                break;
            }
            
        }
        
    }
    
    if ( !found ) {
        printf( "0\n" );
    }
    
    return 0;

}