#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

    int num(string S, string T) {
        int slen = S.length(), tlen = T.length();
        if(slen < tlen) return 0;
        int **rec = new int*[slen+1];
        int i, j;
        for(i = 0; i <= slen; ++i){
            rec[i] = new int[tlen+1];
            for(j = 0; j <= tlen; ++j){
                rec[i][j] = 0;
            }
        }
        for(i = 0; i <= slen; rec[i++][0] = 1);
                
        for(i = 1; i <= slen; ++i){
            for(j = 1; j <= tlen; ++j){
                rec[i][j] = (rec[i-1][j] + (S[i-1] == T[j-1] ? rec[i-1][j-1] : 0));
            }
        }
        
        return rec[slen][tlen];
    }
int main()
{
	//Bulbbasaur
	string s;
	cin>>s;
	string t="Bulbasaur";
	cout<<num(s,t)<<endl;
	return 0;
}