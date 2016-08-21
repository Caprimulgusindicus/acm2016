#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

std::vector<long long> lef[222222],rig[222222];
int w[222222];
int lid[222222],rid[222222];

int main()
{
    int T=1;
    while(T--)
    {
        set<int>S;
   		int n,m;
    	while(~scanf("%d%d",&n,&m))
    	{
    		long long ans=0;
    		S.clear();
    		for(int i=0;i<=n;i++)
        		lef[i].clear(),rig[i].clear();
        
        	for(int i=2;i<=n;i++)
        		scanf("%d",&w[i]);
        	
        	for(int i=1;i<=m;i++)
   			{
   				int p,q;
   				scanf("%d%d",&p,&q);
   				if(p>q) swap(p,q);
   				lef[p].push_back(i);
   				rig[q].push_back(i);
   			}
        
        	for(int j=0;j<lef[1].size();j++)
        		S.insert(lef[1][j]);
        
        	for(int i=2;i<=n;i++)

            {
            	if(!S.empty())
            	{
                	lid[i]=*S.begin();
                	rid[i]=*(--S.end());
            	}
            	else lid[i]=rid[i]=0;
            for(int j=0;j<rig[i].size();j++)
            	S.erase(rig[i][j]);

            for(int j=0;j<lef[i].size();j++)
            	S.insert(lef[i][j]);
        }
        for(int i=0;i<=m;i++)
        	lef[i].clear(),rig[i].clear();
        
        for(int i=2;i<=n;i++)
        {
            lef[lid[i]].push_back(i);
            rig[rid[i]].push_back(i);
        }

        int tmp=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<lef[i].size();j++)
            	tmp+=w[lef[i][j]];
            printf("%d\n",tmp);
            
            for(int j=0;j<rig[i].size();j++)
            	tmp-=w[rig[i][j]];
        }
    }
    }
    return 0;

}