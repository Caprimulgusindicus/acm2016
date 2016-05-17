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
        int k=0;
        memset(cou,0,sizeof(cou));
        memset(s,0,sizeof(s));
        getchar();char c;

            scanf("%s",&s);
            //s[i]=c;
            //cou[c]++;
            //printf("%d\n",c);

        k=n;
        if(n>26) cout<<-1<<endl;
        else
            {
                for(int i=0;i<n;i++)
                    cou[s[i]-'a']=1;
            for(int i=0;i<26;i++)
                ans+=cou[i];
            cout<<k-ans<<endl;
            }

    }
    return 0;
}
