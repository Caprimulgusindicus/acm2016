#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);
        if(b%a==0)
            cout<<a<<" "<<b<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
