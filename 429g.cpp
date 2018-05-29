#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[111][111];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[i][i]=n;
		}
		//int pos=1; //代表出现空缺的盘子
		cout<<"1 1 0"<<endl; //先把第一个盘子里的一块1放进小盘子
		for(int i=1;i<=n;i++){//对每个盘子进行判断
			for(int j=i+1;j<=n;j++){ //找下一个盘子
				printf("%d %d %d\n",j,j,i); //把第i个盘子的i披萨放到空缺的位置上
				if(j<n) printf("%d %d %d\n",i,i,j);
				else {
					int pos=i+1;
					if(pos!=n) 
					{
						printf("%d %d %d\n",i+1,i+1,j);
					}
				}
		
			} 
					
		}
		printf("%d %d %d\n",0,1,n);
		
	}
}