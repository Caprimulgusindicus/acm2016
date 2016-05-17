#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,d;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int x1=i+b-c;
        int x2=i+a-d;
        int x3=i+b-c+a-d;
        if((x1>=1&&x1<=n)&&(x2>=1&&x2<=n)&&(x3>=1&&x3<=n)) ans++;
    }

    cout<<ans*n<<endl;
    return 0;
}
