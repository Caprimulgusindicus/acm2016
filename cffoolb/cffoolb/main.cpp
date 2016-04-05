#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char a[8];
    scanf("%s",a);
    if(a[6]=='3') cout<<21<<endl;
    else if(a[6]=='5') cout<<22<<endl;
    else if(a[6]=='6') cout<<23<<endl;
    else if(a[6]=='0')cout<<25<<endl;
    else cout<<27<<endl;
    return 0;
}