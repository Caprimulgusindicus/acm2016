#include <stdio.h>
#include <iostream>
#include <strstream>
#include <cstring>
#include <sstream>
using namespace std;
int vis[111];
int main()
{
    int n,m;
    int ans=0;
    stringstream ss;
    //((a mod c) + (b mod c)) mod c
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int t=i+j;
            ss<<t;
            string s1=ss.str();
            int len=s1.length();
            if(s1[len-1]=='0'||s1[len-1]=='5') ans++;
        }

    printf("%d\n",ans);
    return 0;
}
