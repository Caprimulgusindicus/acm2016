#include<iostream>
#include <stdio.h>
using namespace std;
char a[22];
int main()
{
    int ca;
    scanf("%d",&ca);
    for(int c=1;c<=ca;c++)
    {
        scanf("%s",&a);
        getchar();
        cout<<a<<endl;
        int len=0;
        for(int i=0;i<=22;i++)
            if(a[i]!='\0') len++;
            else break;
        cout<<len<<endl;
        for(int i=0;i<len;i++)

    }
    return 0;
}
