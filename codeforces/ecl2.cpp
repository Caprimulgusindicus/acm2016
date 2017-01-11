#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int d,x,y;
    node(){}
    node(int a,int b,int c)
    {
        d = c;
        x = a;
        y = b;
    }
};
vector<node> v;
void add(int x,int y,char *s)
{
    if(s[0] == '?')
        return ;
    int sum = 0;
    for(int i = 0; s[i]; i++)
        sum = sum*10+s[i]-'0';
    v.push_back(node(x,y,sum));
}
char s[20];
bool judge(node &a)
{
    int d = a.d;
    for(int i = 1; i*i <= d; i++)
    {
        if(d%i==0&&((a.x<i&&a.y<d/i)||(a.x<d/i&&a.y<i)))
            return true;
    }
    return false;
}
bool getr(int &r,int &c)
{
    node b = v[1],a = v[0];
    int d = a.d;
    for(int i = 1; i*i <= d; i++)
    {
        if(d%i==0&&a.x<i&&a.y<d/i)
        {
            r = i - a.x,c = d/i-a.y;
            int dx = r+b.x,dy = c+b.y;
            if(dx*dy == b.d)return false;
        }
        if(d%i==0&&a.x<d/i&&a.y<i)
        {
            r=d/i-a.x,c=i-a.y;
            int dx = r+b.x,dy = c+b.y;
            if(dx*dy == b.d)return false;
        }
    }
    return true;
}
bool judge()
{
    if(v.size() == 1)
        return judge(v[0]);
    else if(v.size()>1)
    {
        int r,c;
        if(getr(r,c))return false;
        for(int i = 2; i < v.size(); i++)
        {
            if((r+v[i].x)*(c+v[i].y) != v[i].d)
                return false;
        }
    }
    return true;
}
int main()
{
    int t,kase = 1;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%s",s);
                add(i,j,s);
            }
        }
        if(judge())
            printf("Case #%d: Yes\n",kase++);
        else
            printf("Case #%d: No\n",kase++);
    }
    return 0;
}
