#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int a[105];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=n;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                swap(a[j],a[j-1]);
                printf("%d %d\n",j-1,j);
            }
        }
    return 0;
}
