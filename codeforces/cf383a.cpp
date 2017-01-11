#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	
	int n;
	while(~scanf("%d",&n)){
	if(n!=0)
	{
	int t=n%4;
	if(t==1) cout<<8<<endl; 
	else if(t==2) cout<<4<<endl;
	else if(t==3) cout<<2<<endl;
	else cout<<6<<endl;
	}
	else cout<<1<<endl;
}
	return 0;
}