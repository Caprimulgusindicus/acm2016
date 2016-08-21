#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	cout<<123456-123456/10*10<<endl;
	cout<<(123456-123456/100*100)/10<<endl;
	cout<<(123456-123456/1000*1000)/100<<endl;
	cout<<(123456-123456/10000*10000)/1000<<endl;
	cout<<(123456-123456/100000*100000)/10000<<endl;
	cout<<(123456-123456/1000000*1000000)/100000<<endl;

	return 0;
}