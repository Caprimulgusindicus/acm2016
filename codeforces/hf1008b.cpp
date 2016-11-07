//她妈个鸡为什么我用了STL就会TLE呢
//省略一万个字的脏话
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef        vector<pair<int, int> > Type_vector;

int a[111];
int x;
int dp[111][111];
int minn;
int n,m;
int abs(int n)
{
    return n>0?n:-n;
}


int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        minn=2222;
    
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        

        vector < pair <int,int> > pa;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        for(int i=1;i<=n;i++)
        {
            dp[i][i]=a[i];
            pair <int,int> pii=make_pair(dp[i][i],1);
            pa.push_back(pii);
        }  

        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1]^a[j];
                pair <int,int> pii=make_pair(dp[i][j],j-i+1);
                pa.push_back(pii);
            }    
       // sort(pa.begin(),pa.end());
        //cout<<pa.size()<<endl;
        /*for(auto it=pa.begin();it!=pa.end();it++)
        { 
            pair <int,int> tmp=*it;
            cout<<tmp.first<<" "<<tmp.second<<endl;
        }*/
        scanf("%d",&m);
            
        for(int k=1;k<=m;k++) 
        {
            scanf("%d",&x);
                int len=0;minn=1e9;
                Type_vector::iterator i;
                for( i=pa.begin(); i!=pa.end();i++)
                {
                    pair <int,int> tmp=*i;
                    int t=abs(x-tmp.first);
                    //cout<<t<<"  t ";
                    if(t<=minn)
                    {
                        if(t==minn)
                        {
                            len=max(tmp.second,len);
                        }
                        else len=tmp.second;
                        minn=t;
                    //        cout<<len<<" len "<<minn<<" min ";
                    }
                //    cout<<endl;
                }
             cout<<len<<endl;
            }
        cout<<endl;
    }
    return 0;
}