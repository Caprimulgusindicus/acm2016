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
    ˫ɫ��ŵ�����⣨ϰ��2-9��
    Ҫ���õݹ���η����˫ɫ��ŵ�����⣬����Ҫ���ϰ�⣬�����������и��Ӷȷ�����
    ����ϰ���е�Ҫ��ѡ��������ͬѧ��Ӧ��������ļ������Լ�������ļ��е����ݾ�����Ļ�Ͻ�����ʾ��
    */
    //freopen("input.txt","r",stdin);

    while(~scanf("%d",&n))
    {
        hanoi(n,'A','C','B');
    }
    return 0;
}
