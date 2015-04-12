/*
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 10
#define MAXL 15

using namespace std;

struct state {
    char name[MAXL];
    int money, init_money;
};

state people[MAXN];
char name[MAXL];
int NP, money, how;

int find_index( char *name ) {

    int ret = -1;

    for ( int i = 0; i < NP; ++i ) {
        if ( strcmp( people[i].name, name ) == 0 ) {
            ret = i;
            break;
        }
    }
    
    return ( ret );

}

int main( ) {

    freopen( "gift1.in", "r", stdin );
    freopen( "gift1.out", "w", stdout );

    scanf( "%d", &NP );

    for ( int i = 0; i < NP; ++i )
        scanf( "%s", people[i].name );
    
    for ( int i = 0; i < NP; ++i ) {
    
        scanf( "%s %d %d", name, &money, &how );
        
        int whom = find_index( name );
        
        people[ whom ].init_money = money;
        
        if ( how == 0 ) {
            people[ whom ].money += money;
            continue;
        }
        
        int each = money / how;
        
        people[ whom ].money += money - each * how;
        
        for ( int j = 0; j < how; ++j ) {
            scanf( "%s", name );
            people[ find_index( name ) ].money += each;
        }
        
    }
    
    for ( int i = 0; i < NP; ++i ) {
        printf( "%s %d\n", people[i].name, people[i].money - people[i].init_money );
    }
    
    return 0;

}