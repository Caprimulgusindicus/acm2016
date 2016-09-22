#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstdio>
#define ret(i,a,b) for(int i=(a);i<=(b);i++)
#define retr(i,a,b) for(int i=(a);i>=(b);i--)
#define cl(a) memset((a),0,sizeof(a))
using namespace std;
typedef long long ll;
	
ll X[30][11];//X[i][j] 长度为i 以j开头满足条件的个数
ll Y[30][11];
/*	Y[i][j] 长度为i 以j开头，
	前面再加一个与j同奇偶性的数就满足条件的数
	如   1112   223等
*/

void init() {
	cl(X);
	cl(Y);
	for(int i = 0; i <=9; ++i) {
		if(i&1) Y[1][i]=1;
		else X[1][i]=1;
	}//先处理长度为1的
	ret(i,1,19)	//长度
	ret(j,0,9) //数字
	if(j&1) {
		for(int k = 1; k <=9; k+=2) Y[i+1][k]+=X[i][j];
		//如果长度为i，j(奇数)开头是满足条件的
		//那前面再加一个奇数就变成差一位满足(Y)
		for(int k = 0; k <=8; k+=2) X[i+1][k]+=X[i][j];
		//如果长度为i，j(奇数)开头是满足条件的
		//前面加一个偶数也是完全满足的
		for(int k = 1; k <=9; k+=2) X[i+1][k]+=Y[i][j];
		//如果长度为i，j(奇数)开头是差一位满足条件的 (Y)
		//那前面加一个奇数就满足条件
	} else {
		for(int k = 1; k <=9; k+=2) Y[i+1][k]+=X[i][j];
		for(int k = 0; k <=9; k+=2) Y[i+1][k]+=X[i][j];
		for(int k = 0; k <=9; k+=2) X[i+1][k]+=Y[i][j];
	}//偶数同理，推一下就好了
}
/*
	假设我们要算1-77899988有多少个
	那应该是1-9999999中满足的个数
	加上70XXXXXX 71XXXXXX ...76XXXXXX中的个数
	加上770XXXXX 771XXXXX ...777XXXXX中的个数
    7780XXXX 7781XXXX ...7788XXXX中的个数
	....
	...
	7789990X 7789991X...7789997X中的个数
	但当我们要要算77899980-77899987的时候
	我们发现999已经是不满足了 就可以返回了
*/
ll solve(char s[30]) { //计算[1，S-1]里有几个满足条件的
	//假设我传进来的是77899988
	int len = strlen(s);
	int numb[30];
	for(int i = 0; i < len; ++i) numb[i]=s[i]-'0';
	ll ret = 0;
	for(int i = 1; i < len; ++i)
		for(int j = 1; j <=9; ++j)
			ret += X[i][j];
	//这里计算 X XX XXX ....  XXXXXX 即1-9999999有多少个
	for(int i = 1; i < numb[0]; ++i)
		ret += X[len][i];
	//这里计算1XXXXXXX 2XXXXXXX ...6XXXXXXX有多少个

	int cnt = 1; //连续的奇数或偶数长度
	bool odd;
	if(numb[0]&1) odd=true;//第一位是否为奇数
	else odd=false;

	for(int i = 1,nowlen=len-1; i<len; ++i,nowlen--) {	//每次循环固定第一位
		/*
			第一次循环计算71XXXXXX 72XXXXXXX...76XXXXXXX
			第二次循环计算771XXXXX 772XXXXXX...777XXXXXX
			一直重复
		*/
		ret(k,0,numb[i]-1) {
			if(odd&&cnt&1) {
				//前一位是奇数，连续个数也是奇数，那就要加上一个奇数开头,差一位满足的串
				//如7XXXXXXX应该加上71XXXXXX 73XXXXXX...75XXXXX这些
				// 且要求1XXXXXX是1开头，但只能有奇数个的串
				if(k&1)
					ret+=Y[nowlen][k];
			} else if(odd&&!(cnt&1)) {
				ret+=X[nowlen][k];
				//前一位是奇数，连续个数是偶数，那此时已经满足了，再加上一个满足的串就好了
			} else if(!odd&&cnt&1) {
				/*
					如果前一位是偶数，个数是奇数，此时已经满足了
					如果要加奇数开头的串都可以
					如果要加偶数开头的串 那只能加长度是偶数的，也就是差一位满足的才行
				*/
				if(k%2==0) ret+=Y[nowlen][k];
				else ret+=X[nowlen][k];
			} else {
				if(!(k&1)) ret+=X[nowlen][k];
				/*
					前一位是偶数，个数是偶数，那加一个偶数开头，长度为奇数的串
					也就是满足的偶数开头的串
				*/
			}
		}

		/*这里更新奇偶性和个数*/
		if((odd)&&(numb[i]&1)) {
			cnt++;
		} else if((odd)&&(numb[i]%2==0)) {
			if(cnt&1) return ret;
			//假如这一位固定以后就不行了，那就可以返回了
			//比如算到7789991X 778999X2X...7789997XX结束后
			//我们该算7789998X了 但是999显然已经不满足了 就可以退出了
			//如果可行，我们就继续
			odd=!odd;
			cnt=1;
		} else if((!odd)&&(numb[i]%2==0)) {
			cnt++;
		} else {
			if(cnt%2==0)
				return ret;
			odd=!odd;
			cnt=1;
		}
	}
	return ret;
}

void lts(ll x,char s[30]) { //ll转字符
	if(x==0) {
		s[0]='0';
		s[1]=0;
		return;
	}
	int cnt = 0;
	while(x>0) s[cnt++]=x%10 +'0',x/=10;
	s[cnt]=0;
	reverse(s,s+cnt);
}
int main() {

	int kase = 0;
	init();
	int T;
	scanf("%d",&T);
	while(T--) {
		printf("Case #%d: ",++kase);
		char s[30],ss[30];
		ll a,b;
		scanf("%lld %lld",&a,&b);
		b++;//因为solve(x)是算1 - X-1 所以我们要输出solve(b+1)-solve(a)
		lts(a,s);
		lts(b,ss);
		ll ans = solve(ss)-solve(s);
		printf("%lld\n",ans);
	}

	return 0;
}