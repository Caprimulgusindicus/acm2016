#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdio>
#include <sstream>
using namespace std;
int a[5555];
int main()
{
    stringstream ss;
    string x="123456789";//1112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100";
    for(int i=10;i<=1000;i++)
    {
        char t[256];
        string s;
        sprintf(t, "%d", i);
        s = t;
        x+=s;

    }

    char *p=new char[x.size()+1];
    strcpy(p,x.c_str());
    int n;
    for(int i=0;i<=120;i++)
        cout<<x[i]<<endl;
    while(~scanf("%d",&n))
    {
        //int ans=std::atoi(x[n].c_str());
        printf("%c\n",p[n-1]);
    }
    return 0;
}
