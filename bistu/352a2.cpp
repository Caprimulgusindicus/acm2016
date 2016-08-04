#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    long long n;
    long long a[1111];
    int cnt=0;int k=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        long long r=0;
        k=i;
        while(k>0)
        {
            r++;
            a[r]=k%10;
            k/=10;
        }
        for(int i=r;i>0;i--)
        {
            cnt++;
            if(cnt==n)
                cout<<a[i]<<endl;
        }
    }
}
