#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node
{
    friend bool operator < (node n1,node n2)
    {
        return n1.priority<n2.priority;
    }
    int priority;
    int value;
};

int main()
{
    //从大到小
    priority_queue<int> pq;
    //从小到大
    priority_queue<int,vector<int>,greater<int>> pq2;
    //重载比较符

    priority_queue <node> qnode;
    node b[6];
    b[0].priority=6;
    b[1].priority=4;
    b[2].priority=5;
    b[3].priority=3;
    b[4].priority=2;
    b[5].priority=1;


    for(int i=1;i<=6;i++)
    {
        int k;
        scanf("%d",&k);
        pq.push(k);
    }
        cout<<pq.size()<<endl<<endl;
        int len=pq.size();
    for(int i=0;i<len;i++)
    {
        cout<<pq.top()<<endl;
        int x=pq.top();
        pq2.push(x);
        pq.pop();
    }
    cout<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<pq2.top()<<endl;
        int x=pq2.top();
        b[i].value=x;
        qnode.push(b[i]);
        pq2.pop();

    }
    cout<<endl;

    for(int i=1;i<=6;i++)
    {
        cout<<qnode.top().priority<<" "<<qnode.top().value<<endl;
        qnode.pop();
    }
    return 0;
}