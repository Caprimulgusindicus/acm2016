#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a,b;
    int ans=0;
    scanf("%d%d",&a,&b);
    if(a==1&&b==1) cout<<0<<endl;
    else{
    while(a&&b)
    {
        if(a<=b) a+=1,b-=2;
        else b+=1,a-=2;
        ans++;
    }

     cout<<ans<<endl;
     }
    return 0;
}
