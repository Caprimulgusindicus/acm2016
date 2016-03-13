#include <iostream>
#include <stdio.h>
using namespace std;
int t;
int main()
{
    scanf("%d",&t);
    if(t==0) return 0;
        for(int i=1;i<=t;i++)
        {
            int a;int b;
            int ans=0;
            scanf("%d%d",&a,&b);
    if(a==0||b==0) printf("%d\n",0);
           // if(a==b) printf("%d\n",1);
            //else
            //{
                if(a>b) swap(a,b);
                while(b>a)
                {
                    ans++;
                    b-=a;
                    //cout<<a<<endl;
                   // cout<<b<<endl;
                    if(b>=a) continue;
                    else
                    {
                        swap(a,b);
                    }
                }

            //}
            //if(a==b) ans++;
            printf("%d\n",ans+1);

        }
}
