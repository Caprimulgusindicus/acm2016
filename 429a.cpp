#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int n;
	int f=-1111111111;
	//cout<<f<<endl;
	int pos=-1;
	while(~scanf("%d",&n)){
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		if(t>f) f=t,pos=i;
	}
	if(pos==1) printf("%d %d %d\n",n,1,2);
	else if(pos==n) printf("%d %d %d\n",pos-1,n,1);
	else printf("%d %d %d\n",pos-1,pos,pos+1);
	}
}