#include<stdio.h>
#include<cstring>
#include<iostream>

using namespace std;
typedef long long LL;
LL dp[20][10][3]={},f[18]={}; //1表示递增，2表示递减，0表示相同 
int a[20]={};
LL dfs (int pos,int x,int lis,bool lim){
	LL ans=0;
	int num;
	if (pos<=1) return 1;
	if (dp[pos][x][lis]!=-1 && !lim) return dp[pos][x][lis];
	num=lim?a[pos-1]:9;
	for (int i=0;i<=num;i++){
		int lim1=0;
		if (lim && i==num) lim1=1;
		if (i==x && lis==0) ans+=dfs(pos-1,i,0,lim1);
		//if (i==x && lis!=0) ans-=dfs(pos-1,i,0,lim1);
		if (i>=x && lis==1) ans+=dfs(pos-1,i,1,lim1);
		if (i<=x && lis==2) ans+=dfs(pos-1,i,2,lim1);
	}
	if (!lim) dp[pos][x][lis]=ans;
	return ans;
}
LL solve(LL x){
	LL pos=0,ans=0;
	memset(a,0,sizeof a);
	//memset(dp,-1,sizeof dp);
	while (x>0){
		pos++;
		a[pos]=x%10;
		x=x/10;
	}
	for (int i=1;i<a[pos];i++) ans+=dfs(pos,i,1,0)+dfs(pos,i,2,0)-dfs(pos,i,0,0);
	ans+=dfs(pos,a[pos],1,1)+dfs(pos,a[pos],2,1)-dfs(pos,a[pos],0,1);
	//cout << dfs(pos,a[pos],1,1) << " " << dfs(pos,a[pos],2,1) << " " << dfs(pos,a[pos],0,1) << endl;
	return ans+f[pos-1];
}
LL init (){
	LL x=0;
	for (int i=1;i<=18;i++){
		x=x*10+9; 
		f[i]=solve(x);
	}
}
int main(){
	LL T,l,r;
	cin >> T;
	memset(dp,-1,sizeof dp);
	init();
	while (T--){
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
} 