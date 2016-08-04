#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long size=1000;
bool prime[size+5]={false};
int main()
{
    prime[2]=true;
    for(long long i=3;i<=size;i+=2)
        prime[i]=true;
    for(long long i=3;i<=size;i++)
    {
        if(prime[i])
        {
            int cnt=2;
            while(cnt*i<=size)
            {
                prime[cnt*i]=false;
                cnt++;
            }
        }
    }
    int cnt=0;
    for(int i=2;i<=size-2;i++)
    {
        if(prime[i]&&prime[i+2])
            cnt++;


    }
    cout<<cnt<<endl;
    return 0;
}
