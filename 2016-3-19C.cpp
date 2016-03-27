#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        for(int a=1;a<=n;i++)
            for(int q=1;q<=n;q++)
                for(int m=1;m<=n;m++)
        {
            if(a*(1-q^m)/(1-q)==n) ans++;
        }
    }
}
