#include <iostream>
#include <stdio.h>
using namespace std;
int a[111];
int ans=0;
int main()
{
    int n,index;
    scanf("%d%d",&n,&index);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int maxdist=max(index,n-index);
    ans=0;
    //cout<<ans<<endl;
    for(int i=0;i<=maxdist;i++)
        if(i==0&&a[index]==1) ans++;
        else if(a[index-i]==1&&a[index+i]==1&&index-i!=index+i) ans=ans+2;//,cout<<ans;
        else if((index-i<1)&&a[index+i]==1) ans++;//,cout<<ans<<endl;
        else if(index+i>n&&a[index-i]==1) ans++;//,cout<<ans<<endl;

    cout<<ans<<endl;
    return 0;
}
