#include <stdio.h>
#include <iostream>
using namespace std;
char a[1111111];
int bs(int x)
{
    if(x>0) return x;
    else return -x;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    scanf("%s",&a);
    for(int i=0;i<n;i++)
    {
        int tmp=max(bs('z'-a[i]),bs('a'-a[i]));
        int tt=min(k,tmp);
        if(bs('z'-a[i])>bs('a'-a[i]))
            a[i]+=tt;
        else a[i]-=tt;
        k-=tt;
        //cout<<tt<<endl;
    }
    if(k>0) cout<<-1;
    else
        for(int i=0;i<n;i++)
            cout<<a[i];
    cout<<endl;
    return 0;
}
