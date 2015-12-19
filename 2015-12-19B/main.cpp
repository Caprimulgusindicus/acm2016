#include <iostream>
#include <stdio.h>
using namespace std;
int cal(int n,int k)
{
int i = 1;
int temp1 = 1,temp2 =1;
if (n==k)
{
return 1;
}
else
{
for (i=1;i<=k;i++)
{
temp1 *= n-i+1;
temp2 *=i;
}
temp1 /=temp2;
return temp1;
}
}
int main()
{
    int n,m;
    int a[111111];
    while(~scanf("%d%d",&n,&m))
    {
        int tmp=n-m;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        cout<<cal(n,2)-tmp<<endl;
    }
    return 0;
}
