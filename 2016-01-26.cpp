#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <string.h>
using namespace std;
int k;
int cmp(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}
int main(){
	int i,n,m,k,j,a[110],b[110],c[110];
	while(~scanf("%d%d",&n,&m)){
            memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
            memset(c,23333,sizeof(c));
		if(!n &&  !m) return 0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<m;i++)
		    scanf("%d",&b[i]);
		qsort(a,n,sizeof(a[0]),cmp);
		qsort(b,m,sizeof(b[0]),cmp);
		int k=0;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(a[i]==b[j]){
					c[k]=i;
					k++;continue;
				}
			}
		}
		k=0;
		for(i=0;i<n;i++){
			if(i==c[k]){
				k++;
				continue;
			}
			printf("%d ",a[i]);
		}
		if(k==i)
	      printf("NULL\n");
		else
		  printf("\n");

	}
	return 0;
}
