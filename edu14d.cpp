#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
#define mod 1000000007
using namespace std;

vector<int> arr;
vector<int> visited;
vector<int> pos;
vector<vector<int>> v;
vector<int> row;

 void dfs(int i)
 {
        for(int j=0;j<v[i].size();j++)
        {
            int val=v[i][j];
            if(visited[val] == 0)
            {
                visited[val] = 1;
                row.push_back(arr[val]);
                pos.push_back(val);
                dfs(val);
            }
        }
    return;
 }

int main()
{
   
    int n,k;
    scanf("%d%d",&n,&k);
    v.resize(n+1);
    arr.resize(n+1);
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=0;i<k;i++)
    {
        int x;
        int y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    visited.resize(n+1);
    for(int i=1;i<=n;i++)
        visited[i]=0;

    vector<int> res(n+1);
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0){
            visited[i]=1;
            row.clear();
            pos.clear();
            row.push_back(arr[i]);
            pos.push_back(i);
            dfs(i);
            sort(row.rbegin(),row.rend());
            sort(pos.begin(),pos.end());
            for(int j = 0;j<row.size();j++)
                res[pos[j]]=row[j];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",res[i]);
    cout<<endl;
    return 0;
}