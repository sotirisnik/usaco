/*
TASK: castle
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAXN 50

using namespace std;

struct state {
    bool west, north, east, south;
};

state can_go[MAXN+1][MAXN+1];
int visited[MAXN+1][MAXN+1];
int room_size[MAXN*MAXN+1];
int n, m, x, color, maxu, maxu_join, wall_x, wall_y;
char dir;

bool valid( int x, int y ) {
    return ( x >= 1 && y >= 1 && x <= n && y <= m );
}

void flood_fill( int x, int y ) {

    if ( visited[x][y] != 0 ) {
        return;
    }

    visited[x][y] = color;
    
    ++room_size[color];
    
    if ( can_go[x][y].west && valid( x, y-1 ) ) flood_fill( x, y-1 );
    if ( can_go[x][y].north && valid( x-1, y ) ) flood_fill( x-1, y );
    if ( can_go[x][y].east && valid( x, y+1 ) ) flood_fill( x, y+1 );
    if ( can_go[x][y].south && valid( x+1, y ) ) flood_fill( x+1, y );
    
}

void map_moves( int i, int j, int x ) {

    if ( x >= 8 ) {
        can_go[i][j].south = false;
        x -= 8;
    }else {
        can_go[i][j].south = true;
    }
    
    if ( x >= 4 ) {
        can_go[i][j].east = false;
        x -= 4;
    }else {
        can_go[i][j].east = true;
    }
    
    if ( x >= 2 ) {
        can_go[i][j].north = false;
        x -= 2;
    }else {
        can_go[i][j].north = true;
    }
    
    if ( x >= 1 ) {
        can_go[i][j].west = false;
        x -= 1;
    }else {
        can_go[i][j].west = true;
    }

}

int main( ) {

    freopen( "castle.in", "r", stdin );
    freopen( "castle.out", "w", stdout );

    scanf( "%d %d", &m, &n );    
    
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= m; ++j ) {
            scanf( "%d", &x );
            map_moves( i, j, x );
        }
    }
    
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= m; ++j ) {
            if ( visited[i][j] == 0 ) {
                ++color;
                flood_fill( i, j );
            }
        }
    }
    
    printf( "%d\n", color );
    
    int maxu = room_size[1];
    
    for ( int i = 1; i <= color; ++i ) {
        maxu = max( maxu, room_size[i] );
    }
    
    printf( "%d\n", maxu );
    
    int maxu_join = 0;
    int row = 0;
    int col = 0;
    char dir = '#';
    
    for ( int j = 1; j <= m; ++j ) {
        for ( int i = n; i >= 1; --i ) {
        
            if ( valid( i-1, j ) ) {
                if ( visited[i][j] > 0 && visited[i-1][j] > 0 && visited[i][j] != visited[i-1][j] ) {
                    int next_maxu = room_size[ visited[i][j] ] + room_size[ visited[i-1][j] ];
                    if ( next_maxu > maxu_join ) {
                        maxu_join = next_maxu;
                        row = i;
                        col = j;
                        dir = 'N';
                    }
                }
            }
            
            if ( valid( i, j+1 ) ) {
                if ( visited[i][j] > 0 && visited[i][j+1] > 0 && visited[i][j] != visited[i][j+1] ) {
                    int next_maxu = room_size[ visited[i][j] ] + room_size[ visited[i][j+1] ];
                    if ( next_maxu > maxu_join ) {
                        maxu_join = next_maxu;
                        row = i;
                        col = j;
                        dir = 'E';
                    }
                }
            }
            
        }
    }
    
    printf( "%d\n", maxu_join );
    
    printf( "%d %d %c\n", row, col, dir );
    
    return 0;

}