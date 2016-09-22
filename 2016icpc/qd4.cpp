#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f;
const int maxn=1e6+10;
double num[maxn];


char n[maxn];
int main()
{
     num[1]=1.0;
    for(int i=2;i<=maxn-1;i++){
                double ii=(double)i;
                num[i]+=num[i-1];
                num[i]+=(1/(ii*ii));
            }
    while(~scanf("%s",n))
    {
        
         
        int len=strlen(n);
        if(len>6){
            printf("%.5lf\n",num[maxn-1]);
        }
        else{
            int nn=0;
            for(int i=0;i<len;i++){
                nn*=10;
                nn+=(n[i]-'0');
            }
            printf("%.5lf\n",num[nn]);
        }
    }
    return 0;
}
