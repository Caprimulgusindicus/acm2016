#include <stdio.h>
#include <string.h>
#define clr(a,b) memset(a,b,sizeof a)
const int N = 1005;
char str[N];
int a[N];
int b[N];
int getlen()
{
	for(int i = N - 1; i >= 0; i--)
		if(a[i]) return i + 1;
	return 0;
}
int getlenb()
{
	for(int i = N - 1; i >= 0; i--)
		if(b[i]) return i + 1;
	return 0;
}
void run()
{
	scanf("%s",str);
	int l = strlen(str);
	for(int t = 0, i = l - 1; i >= 0; i--)
		a[t++] = str[i] - '0';
	while(l > 2)
	{
		clr(b,0);
		for(int i = l >> 1; i < l; i++)
			b[i] = a[i];
		for(int i = l >> 1; i < l; i++)
		{
			if(b[i]){b[i]--; break;}
			b[i] = 9;
		}
		int lb = getlenb();
		for(int i = 0, ed = lb >> 1; i < ed; i++)
		{
			b[i] = b[lb - 1 - i];
		}
		for(int i = lb - 1; i >= 0; i--) printf("%d", b[i]);puts("");
		for(int i = 0; i < l; i++)
		{
			a[i] -= b[i];
			if(a[i] < 0)
			{
				a[i] += 10;
				b[i + 1]++;
			}
		}
		l = getlen();
	}
	if(l)
	{
		int nowa = a[0] + 10 * a[1];
		for(int i = 9; i >= 0; i--)
		{
			int x = 11 * i;
			if(i == 0) x = 9;
			if(nowa - x >= 0)
				printf("%d\n", x), nowa -= x;
		}
		if(nowa) printf("%d\n", nowa);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		
		run();
	}
	return 0;
}