#include <iostream>
#include <stdio.h>

using namespace std;
long long n;
long long bx;
long long m;
long long by;
long long pow(int m, int x)   {
    long long ret = 1;
    for (int i=1; i<=x; ++i) {
        ret *= m;
    }
    return ret;
}
int main()
{
    scanf("%I64d%I64d",&n,&bx);

        long long x[12];
        long long y[12];
        long long sumx=0;
        long long sumy=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&x[i]);
            sumx+=x[i]*pow(bx,(n-i));
            //cout<<x[i]<<endl;
            //cout<<<<endl;
           // cout<<sumx<<endl;
        }
        //cout<<sumx<<endl;
        scanf("%I64d%I64d",&m,&by);
        for(int i=1;i<=m;i++)
        {
            scanf("%I64d",&y[i]);
            sumy+=y[i]*pow(by,(m-i));
        }
        //cout<<sumx<<endl;
        //cout<<sumy<<endl;
        if(sumx==sumy) puts("=");
        else if(sumx>sumy) puts(">");
        else puts("<");

    return 0;
}
