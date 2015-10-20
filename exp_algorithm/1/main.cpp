#include <iostream>
#include <stdio.h>
using namespace std;
int  n;

void hanoi(int n,char a,char b,char c)
{
    if(n==1) printf("%d %c %c\n",n,a,c);
    else
    {
        hanoi(n-1,a,c,b);
        printf("%d %c %c\n",n,a,c);
        hanoi(n-1,b,a,c);
    }
}
int main()
{
    /*
    双色汉诺塔问题（习题2-9）
    要求：用递归分治法解决双色汉诺塔问题，具体要求见习题，输出结果并进行复杂度分析。
    除了习题中的要求，选择此问题的同学还应将读入的文件内容以及输出到文件中的内容均在屏幕上进行显示。
    */
    //freopen("input.txt","r",stdin);

    while(~scanf("%d",&n))
    {
        hanoi(n,'A','C','B');
    }
    return 0;
}
