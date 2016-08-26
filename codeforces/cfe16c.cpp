#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX  50		/*宏定义*/

int main()
{

	int magic [MAX][MAX];
	int cur_i=0,cur_j;		
	int count,n ,i,j;
	scanf("%d",&n);

	cur_j = (n-1) / 2;
	for(count=1;count <=n*n;count++)
	{
		magic[cur_i][cur_j] = count;
		if ((count % n == 0)){
			cur_i = cur_i+1; 
			continue;
		}
		cur_i = cur_i-1;
		cur_j = cur_j + 1;
		if (cur_i == -1)
			cur_i += n;
		else if(cur_j>n-1)
			cur_j -= n;

	}

	for (i = 0;i < n;i++){		
		for (j = 0;j <n;j++)
			if(j!=0) printf(" %d",magic[i][j]);
			else printf("%d",magic[i][j]);
			printf("\n");

	}
	return 0;
}
