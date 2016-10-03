//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
char s[55555];
set <char> ss;
int main()
{
	gets (s);
	int len = strlen(s) ;
	if ( len > = 26 ){
		for ( int i = 1 ; i < = len - 25 ; i++ ) {
			for (int j = i + 26 ; j < = len ; j ++ ) {
				for ( int k = i ; k < = j ;k ++ ) {
					if ( s[i] == '?' ) 
				}
			}
		}
	}
	else puts ("-1") ;
	return 0;
}