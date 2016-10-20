#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const long long mod=1000000007;
ll vis[2222];
ll prime[2222]={0};
ll a[2222];
ll fc[2222][2222];
int pnum;
int n;

int get_primes(int m)//在m以下的质数个数
{
	memset(vis,0,sizeof(vis));
	int cnt=1;
	for(int i=2;i<m;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]=i;
			for(int j=i*i;j<m;j+=i)
				vis[j]=1;
		}
	}
	return cnt;
}

void change(ll k,ll g)//对每一个数分解质因数并把该质因数扔进方程
{
	for(int i=1;i<=pnum;)//分解质因数
	{
		if(k%prime[i]==0)
		{
			fc[i][g]^=1;//i为第几行，g为属于第几列；假设有一个表，行为质因数的序号；列为第i个数分裂出来的质因数
			k/=prime[i];//进行下一轮分解
		}
		else i++;
	}
}

ll gauss()//高斯消元模版
{
	ll g=0;
	int i,j;
	for(j=1;j<=n&&g<pnum;j++)
	{
		for(i=g+1;i<=pnum;i++)
			if(fc[i][j]==1) break;
		if(i<=pnum)
		{
			g++;
			for(int p=j;p<=n;p++)
				swap(fc[g][p],fc[i][p]);
			for(int p=g+1;p<=pnum;p++)
			{
				if(fc[p][j]==1)
					for(int q=j;q<=n;q++)
						fc[p][q]^=fc[g][q];
			}
		}
	}
	return g;
}

ll qpow(ll a,ll b,ll m)//我也不知道为什么要快速幂
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
			b--;
		}
		b/=2;
		a=a*a%m;
	}
	return ans;
}

int main()
{
	get_primes(2100);//获得2000内的质数
	//cout<<get_primes(2000)<<endl;
	pnum=303;
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		memset(fc,0,sizeof(fc));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			change(a[i],i);
		}
		int r=gauss();
		ll ans=qpow(2,ll(n-r),mod)-1;
		printf("Case #%d:\n%lld\n",ca,ans);
	}
	return 0;
}