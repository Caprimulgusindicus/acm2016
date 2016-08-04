#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
//aa aaa aaaa aaaaa
//baab
char s[222222];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        getchar();
        //cout<<s<<endl;
        int len=0;
        int i=0;
        while(s[i]!='\0')
            {len++;i++;}
        //cout<<len<<endl;
        for(int i=0;i<len-1;i++)
        {
            int t;
            if(i!=len-2)
                t=s[i+2]-s[i+1]+1;
            else t=1;
            if(t==0) t=1;
            if(s[i+1]==s[i]) s[i+1]+=t;
            if(s[i+1]>'z') s[i+1]='a';
            //if(s[i+1]<'a') s[i+1]='z';
        }
        printf("%s\n",s);
    }
}
