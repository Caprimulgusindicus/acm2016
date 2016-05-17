#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <hash_map>
using namespace std;
vector <string> a;
int vis[2222];
int ans(string s)
{
    map<string,int> m;

            sort(s.begin(),s.end());
            cout<<s<<endl;
            s.push_back(m);
            m[s]++;
            map<string,int>::iterator it=m.find(s);
            //cout<<m[s]<<endl;
           // if(it->second!=0)
           //     vis[it->second]++;
          //  cout<<vis[it->second]<<endl;

}

int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1;i<=test;i++)
    {
        string s;
        cin>>s;
        //cout<<s<<endl;
        //cout<<
        ans(s);
    }

    return 0;
}

