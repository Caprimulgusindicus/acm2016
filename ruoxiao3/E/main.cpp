#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct x
{
    double val;
    int pos;
};
x a[11111];

int cmp(const x &a,const x &b)
{
    return a.val<b.val;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {

        int aans[11111];


        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&a[i].val);
            a[i].pos=i;

        }
        if(n==1)
        {
				cout<<1<<endl<<1<< endl;
				continue;
        }
        sort(a+1,a+1+n,cmp);
        int k=1;
        int ans=0;

        while(k+1<=n&&a[k].val<0&&a[k+1].val<0&&a[k].val*a[k+1].val>1+1e-9)
        {
			aans[ans++]=a[k++].pos;
			aans[ans++]=a[k++].pos;
		}
		k=n;
		while(k&&a[k].val>1+1e-9){
			aans[ans++]=a[k--].pos;
		}

        if(ans==0)
           {

				if(a[1].val*a[2].val>a[n].val+1e-9)
				{
					aans[ans++]=a[1].pos;
					aans[ans++]=a[2].pos;
				}
				else aans[ans++]=a[n].pos;
		}
        if(ans)
        {
            sort(aans,aans+ans);
            cout<<ans<<endl;
            for(int i=0;i<ans-1;i++)
                cout<<aans[i]<<" ";
            cout<<aans[ans-1]<<endl;
        }
    }
    return 0;
}
