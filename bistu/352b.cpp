#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdio>
#include <sstream>
using namespace std;
int cou[200];
char s[111111];
int main()
{
    int n;int ans;
    while(~scanf("%d",&n))
    {
        ans=0;
        memset(cou,0,sizeof(cou));
        memset(s,0,sizeof(s));
        getchar();char c;
        for(int i=1;i<=n;i++)
        {

            scanf("%c",&c);
            s[i]=c;
            cou[c]++;
            //printf("%d\n",c);
        }

       for(int i=96;i<=123;i++)
            if(cou[i]>=2) {ans+=cou[i]-1;}//cout<<i<<endl;}
        if(ans>=26) cout<<"-1"<<endl;
            else cout<<ans<<endl;
    }
    return 0;
}
