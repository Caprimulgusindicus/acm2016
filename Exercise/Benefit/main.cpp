#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a,b,c;

LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b%a==0)
        {
            c=b/a;
            LL g=c;
            while(g!=1)
            {
                g=gcd(c,a);
                c*=g;
                a/=g;
            }
            cout<<c<<endl;
        }
        else
        cout<<"NO SOLUTION"<<endl;
    }
    return 0;
}
