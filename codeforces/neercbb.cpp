#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
vector <int> small,big;
int query(int i,int j)
{
	printf("? %d %d\n",i,j),fflush(stdout);
	char res[5];
	scanf("%s",res);
	return (res[0]=='<'?-1:(res[0]=='='?0:1));
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		small.clear();
		big.clear();
		for(int i=1;2*i<=n;i++)
		{
			if(query(2*i-1,2*i)<0)
				small.push_back(2*i-1),big.push_back(2*i);
			else small.push_back(2*i),big.push_back(2*i-1);
		}

		if(n&1)
			small.push_back(n),big.push_back(n);
		for(int i=1;i<(int)small.size();i++)
			if(query(small[0],small[i])>0)
				small[0]=small[i];

		for(int i=1;i<(int)big.size();i++)
			if(query(big[0],big[i])<0)
				big[0]=big[i];
		printf("! %d %d\n",small[0],big[0]),fflush(stdout);
	}
}