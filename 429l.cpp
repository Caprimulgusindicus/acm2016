#include <cstdio>
#include <iostream>
using namespace std;

double p[200010];//1
double a[200010];//0
char c[200010];
double arr[200010];

int main ()
{
    
    int n;
    scanf("%d",&n);
    int number=0;

    for(int i=0; i<2*n; i++)
    {
        //getchar();
        scanf(" %c %lf",&c[i],&a[i]);

    }

    p[0]=1;
    for(int i=1;i<2*n;i++)
    {
        if(c[i]=='-') p[i]=p[i-1]-1;
        else p[i]=p[i-1]+1;
    }
    int j=0;

    arr[2*n-1]=a[2*n-1];
        
    for(int i=2*n-2; i>=0; i--)
    {
                if(c[i]=='-')
                {
                    arr[i]=(1.0/p[i-1])*a[i]+(1.0-(1.0/p[i-1]))*arr[i+1];
                }
                else arr[i]=arr[i+1];
        }
    
    for(int i=0; i<2*n; i++)
    {
        if(c[i]=='+')
            printf("%.10f\n",arr[i]-a[i]);
    }
    return 0;
}