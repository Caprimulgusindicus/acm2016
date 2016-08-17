#include <iostream>
#include <cstdio>
using namespace std;
bool v[20000000];
int ans[2010];
int pre[2010];
int p,tp;

int main()
{
	tp = p = 1;
	for (int i = 1; i < 2010;i++)
	{
		p = tp;
		while (!ans[i] && p < 20000000)
		{
			while (v[p]) p++;
			pre[i] = pre[i - 1] + p;
			int j = 0;
 			for (; j < i; j++)
				if (v[pre[i] - pre[j]])
				{
					p++;
					break;
				}
			if (j != i)
				continue;
			else
			{
				ans[i] = p;
				v[p] = true;
				v[pre[i]] = true;
				j = 0;
				for (; j < i; j++)
					v[pre[i] - pre[j]] = true;
				for (j = tp; j < p; j++)
					if (!v[j])
						break;
				if (j == p)
					tp = p;
			}
		}
	}
	for (int i = 0; i < 2010; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}