#include <iostream>    
#include <stdlib.h>
#include <cstring>
#include <cstdio>
#include <string.h>
#include <stdio.h>
using namespace std; 
int cnt;
char ttt[1111111];
int Next[1111111];

int KMP(char *A, char *B) {
    memset(Next,0,sizeof(Next));
    int m = strlen(A), n = strlen(B);

    Next[0] = 0;
    for(int i = 1; i < n; i++) {
        int k = Next[i - 1];
        while(B[i] != B[k] && k) k = Next[k - 1];
        Next[i] = B[i] == B[k] ? k + 1 : 0;
    }

    int ans = 0, j = 0;
    for(int i = 0; i < m; i++) {
        while(A[i] != B[j] && j) j = Next[j - 1];
        if(A[i] == B[j]) j++;
        if(j == n) ans++;
    }
    return ans;
}

void func(int n,int p)
{
    int m=0;
    int c;
    char ss[1111111];  
    //cout<<"要转换的进制："<<p<<endl;        
    while (n!=0)//数制转换，结果存入数组s[m]    
    {    
        c=n%p;    
        n=n/p;    
        m++;
        //cout<<c<<endl;
        char a[2];
        if(c>=10) ss[m]= sprintf(a,"%c",c+'57');
        else sprintf(a,"%d",c);
        ss[m]=a[0];
    }    
    
    for(int k=m;k>=1;k--)//输出转换后的序列    
    {     
        ttt[cnt]=ss[k];
        cnt++;  
    }    
}

int main()    
{    
    int n;
    char s[1111111];
    while(~scanf("%d",&n)){
        getchar();
        scanf("%s",s);
        int flag=0;
        for(int k=2;k<=16;k++){
            cnt=0;
            memset(ttt,0,sizeof(ttt));
            for(int i=1;i<=n;i++)
            {
                func(i,k);
            }
            if(KMP(ttt,s)!=0) {puts("yes");flag=1;break;}
        }
        if(!flag) puts("no");
    }
    return 0;    
}    