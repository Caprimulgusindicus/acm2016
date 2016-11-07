#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int flag1;
int flag2;
struct cfx
{
	int x1;
	int y1;
	int x2;
	int y2;
	int w;
	int h;
}a[5555];

int cmp(cfx a,cfx b)
{
	if(a.x1==b.x1) return a.y2<b.y2;
	else return a.x1<b.x1;
}

int main()
{
	int n;
	while(~scanf("%d",&n)&&n!=0)
	{
		int area=0;
		vector <int> vec1;
		vector <int> vec2;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
			a[i].w=a[i].x2-a[i].x1;
			a[i].h=a[i].y2-a[i].y1;
			vec1.push_back(a[i].x1);
			vec1.push_back(a[i].x2);
			vec2.push_back(a[i].y1);
			vec2.push_back(a[i].y2);
		}	
		sort(a+1,a+1+n,cmp);
		sort(vec.begin(),vec.end());
		int l;int r;
		int top;int buttom;

		l=*vec.begin();
		//cout<<l<<endl;
		//cout<<*vec.begin()+1<<endl;
		for(auto it=vec.begin();it!=vec.end();it++)
		{
			r=*it;
			//cout<<r<<" ";
			for(int i=1;i<=n;i++)
			{
				flag1=0;
				vector <int> v;
				vector <cfx> cube;
				if(a[i].x1<r&&a[i].x2>=r)
				{
					cube.push_back(a[i]);
					v.push_back(a[i].y1);
					v.push_back(a[i].y2);
					flag1=1;
				}	//area+=(r-l)*a[i].h;
				sort(v.begin(),v.end());
				for(auto itt=v.begin();itt!=v.end();itt++)
				{
					flag2=0;
					top=*itt;
					//cout<<top<<" ";
					for(auto last=cube.begin();last!=cube.end();last++)
					{	
	 					buttom=top;
						cfx cc =*last;
						if(cc.y1<top&&cc.y2>=top)
							{flag2=1;break;}
					}
					if(flag1&&flag2) area+=(top-buttom)*(r-l);

				}
			}
			l=r;
		}
		cout<<area<<endl;
}
	return 0;
}