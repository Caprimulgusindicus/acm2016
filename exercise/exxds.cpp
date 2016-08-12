#include <cstdio.h>
const maxn=10010;
struct node
{
	int l,r;
	int message;
}seg[maxn*3];

void build(int i,int l,int r)
{
	seg[i].l=l;
	seg[i].r=r;
	seg[i].message=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(1<<i,1,mid);
	build((1<<i),mid,r);
}

void update(int num,int i);
{
	if(条件)
	{
		return;
	}
	int mid=(seg[i].l+seg[i].r)>>1;
	if(num>mid)
		update(num,2*i+1);
	else update(num,2*i);
	seg[i].message=(更新);
}

int query(int l,int r,int i)
{
	if(seg[i].l==l&&seg[i].r==r)
		return seg[i].message;
	int mid=(seg[i].l+seg[i].r)>>1;
	
}
int main()
{
	return 0;
}