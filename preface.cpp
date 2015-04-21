/*
TASK: preface
LANG: C++
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <algorithm>

#define MAXN 7
#define MAXL 13

using namespace std;

char simple_symbol[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
string symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
int val[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
map <char,int> m;
int n;

string roman( int tmp ) {

	string ret = "";

	int cnt = MAXL-1;
	
	while ( cnt >= 0 && tmp > 0 ) {
		if ( tmp >= val[cnt] ) {
			tmp -= val[cnt];
			ret += symbols[cnt];
		}else {
			--cnt;
		}
	}
	
	return ( ret );

}

void count_roman( string tmp ) {

	for ( int i = 0; i < tmp.size(); ++i ) {
		++m[ tmp[i] ];
	}

}

int main( ) {

	freopen( "preface.in", "r", stdin );
	freopen( "preface.out", "w", stdout );
	
	scanf( "%d", &n );
	
	for ( int i = 1; i <= n; ++i ) {
		count_roman( roman( i ) );
	}
	
	for ( int i = 0; i < MAXN; ++i ) {
		if ( m.find( simple_symbol[i] ) != m.end() ) {
			printf( "%c %d\n", simple_symbol[i], m[ simple_symbol[i] ] );
		}
	}

	return 0;

}