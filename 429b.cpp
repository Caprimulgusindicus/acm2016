#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    ll temp;
    do{temp=a%b;a=b;b=temp;}while(temp!=0);return a;
}
int main()
{
	long long l,r,w;

	while(~scanf("%lld%lld%lld",&l,&r,&w)){
	int flag=1;
	if((r+w-gcd(r,w))>l) flag=0;
	//cout<<r<<" "<<w<<endl;
	if(flag) cout<<"OK"<<endl;
	else cout<<"DEADLOCK"<<endl;
}
	return 0;
}