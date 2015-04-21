/*
TASK: lamps
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int n, c, what;
vector <int> ON, OFF;
string start, tmp, top;
queue < pair<string,int> > q;
set < pair<string,int> > s;
set <string> m;

string flip( string tmp ) {

    for ( int i = 0; i < tmp.size(); ++i ) {
        if ( tmp[i] == '1' ) {
            tmp[i] = '0';
        }else {
            tmp[i] = '1';
        }
    }
    
    return ( tmp );

}

string odd( string tmp ) {

    for ( int i = 1; i < tmp.size(); i += 2 ) {
        if ( tmp[i] == '1' ) {
            tmp[i] = '0';
        }else {
            tmp[i] = '1';
        }
    }
    
    return ( tmp );

}

string even( string tmp ) {

    for ( int i = 0; i < tmp.size(); i += 2 ) {
        if ( tmp[i] == '1' ) {
            tmp[i] = '0';
        }else {
            tmp[i] = '1';
        }
    }
    
    return ( tmp );

}

string kform( string tmp ) {

    for ( int i = 0; i < tmp.size(); i += 3 ) {
        if ( tmp[i] == '1' ) {
            tmp[i] = '0';
        }else {
            tmp[i] = '1';
        }
    }
    
    return ( tmp );

}

void check( string tmp ) {
    for ( int i = 0; i < ON.size(); ++i ) {
        if ( tmp[ ON[i] ] == '0' ) {
            return;
        }
    }
    
    for ( int i = 0; i < OFF.size(); ++i ) {
        if ( tmp[ OFF[i] ] == '1' ) {
            return;
        }
    }
    m.insert( tmp );
}

int main( ) {

    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);

    scanf( "%d %d", &n, &c );
    
    while ( scanf( "%d", &what ) && what != -1 ) {
        ON.push_back( what-1 );
    }
    
    while ( scanf( "%d", &what ) && what != -1 ) {
        OFF.push_back( what-1 );
    }
    
    for ( int i = 1; i <= n; ++i ) {
        start += '1';
    }
 
    c = min( c, 4 );
 
    q.push( make_pair(start,c) );
    s.insert( make_pair(start,c) );
    
    while ( !q.empty() ) {
    
        pair<string,int> top = q.front();
        q.pop();
        
        if ( top.second == 0 ) {
            check( top.first );
            continue;
        }
        
        tmp = flip( top.first );
        
        if ( s.find( make_pair(tmp,top.second-1) ) == s.end() ) {
            q.push( make_pair(tmp,top.second-1) );
            s.insert( make_pair(tmp,top.second-1) );
        }
        
        tmp = odd( top.first );
        
        if ( s.find( make_pair(tmp,top.second-1) ) == s.end() ) {
            q.push( make_pair(tmp,top.second-1) );
            s.insert( make_pair(tmp,top.second-1) );
        }
        
        tmp = even( top.first );
        
        if ( s.find( make_pair(tmp,top.second-1) ) == s.end() ) {
            q.push( make_pair(tmp,top.second-1) );
            s.insert( make_pair(tmp,top.second-1) );
        }
        
        tmp = kform( top.first );
        
        if ( s.find( make_pair(tmp,top.second-1) ) == s.end() ) {
            q.push( make_pair(tmp,top.second-1) );
            s.insert( make_pair(tmp,top.second-1) );
        }
        
    }
    
    if ( m.size() == 0 ) {
        printf( "IMPOSSIBLE\n" );
    }else {
        for ( set<string>::iterator pos = m.begin(); pos != m.end(); ++pos ) {
            printf( "%s\n", (*pos).c_str() );
        }
    }
    
    return 0;

}