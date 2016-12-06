#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct enemy
{
	int dps;
	int hp;
};
enemy e[22];

bool cmp(enemy a,enemy b)
{
	return a.hp*b.dps<b.hp*a.dps;
}

int main()
{
	while(~scanf("%d",&n))
	{
		int res=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&e[i].dps,&e[i].hp),res+=e[i].dps;
		
		sort(e+1,e+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=res*e[i].hp;
			res-=e[i].dps;
		}
		cout<<ans<<endl;
	}
	return 0;
}