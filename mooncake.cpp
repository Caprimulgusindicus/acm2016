#include <iostream>
using namespace std;

int main()
{
	pair <int,char> MoonCake[15];
	make_pair(0,"null");
	init();
	MidAutumnFestival(MoonCake);
	while(!Hash(MoonCake))
	{
		Jiaoyi(MoonCake);
	}
	int total=Cal(MoonCake);
	for(int i=1;i<=total;i++)
		cout<<JPG(MoonCake[i].first,MoonCake[i].second)<<endl;
	return 0;
}