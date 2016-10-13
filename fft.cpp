#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <vector>
using namespace std;
set<int> s;
vector<int> v;
int bt[1111111], n, m, lasta, lastb, st, ed;
int ans,sum;

struct node 
{
    int begin;
    int end;
    int w;
};
    	node a[1111111],b[1111111];

void insert(int p,int x) 
{
    while (p<= m) 
    {
        bt[p] += x;
        p += p & (-p);
    }
}

int query (int p) 
{
    int tmp = 0;
    while (p) 
    {
        tmp += bt[p];
        p -= p & (-p);
    }
    return tmp;
}

int find (int l, int r, int x) 
{
	int mid = (l + r) >> 1;
    if (l == r) return l;
    else if (l == r - 1) 
    {
        if (v[l] >= x) return l;
        return r;
    }
    
    if(v[mid]<x) return find (mid + 1, r, x);
    else return find (l, mid, x);
}

void solve()
{
	if (m == 0) puts("0") ;
        else 
        {
            memset (bt, 0, sizeof (bt));
            for (auto it = s.begin ( ); it != s.end (); it++)
                v.push_back (*it);
            n = v.size ();

            for (int i = 0; i < m; i++) 
            {
                if (b[i].end - b[i].begin <= lasta)
                {

	                int t1 = b[i].end - lasta;
	                int l = find (0, n - 1, t1) + 1;
	                int r = find (0, n - 1, b[i].begin) + 1;
	                insert (l, b[i].w);
	                insert (r + 1, -b[i].w);
            	}
            }

            ans = sum;
            for (int i = 0; i < n; i++)
                ans = min (ans, sum - query (i + 1));

            printf ("%d\n", ans);

        }
}

int main ( ) 
{
    while(~scanf("%d%d",&lasta,&lastb)) 
    {
        ans=0;
        sum= 0;
        s.clear ();
        v.clear ();

        scanf ("%d", &st);
        scanf ("%d%d", &n, &m);

        for (int i = 0; i < n; i++)
            scanf ("%d%d%d", &a[i].begin, &a[i].end, &a[i].w);
        for (int i = 0; i < m; i++)
            scanf ("%d%d%d", &b[i].begin, &b[i].end, &b[i].w);
        
        ed = st + lastb;
        

        for (int i = 0; i < m; i++) 
        {
            int l = b[i].begin + b[i].end;
            int r;
            if (l + b[i].end >= st && l + b[i].end <= ed) 
            {
                int t = (ed - b[i].begin) / (2 * b[i].end);
                r = b[i].begin + t * 2 * b[i].end + b[i].end;
            }
            else
                r = l;
            b[i].begin = l, b[i].end = r;
            s.insert (l);
            sum += b[i].w;
        }

        for (int i = 0; i < n; i++) 
        {
            int l = a[i].begin + a[i].end;

            if (l >= st && l <= ed) 
            {
                b[m].w = a[i].w;
                b[m].begin = l + a[i].end;
                s.insert (b[m].begin);
                int t = (ed - l) / (2 * a[i].end), r = l + t * 2 * a[i].end + a[i].end;
                b[m++].end = r;
                sum += a[i].w;
            }
        }
        solve();
        
    }
    return 0;
}