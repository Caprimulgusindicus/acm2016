#include<stdio.h>  
#include<string.h>  
const int mod=10007;  
struct matrix  
{  
    int mat[3][3];  
    matrix friend operator * (matrix a,matrix b)  
    {  
        matrix tp;  
        memset(tp.mat,0,sizeof(tp.mat));  
        for(int i=0;i<3;++i)  
        {  
            for(int j=0;j<3;++j)  
            {  
                if(!a.mat[i][j])  
                {  
                    continue;  
                }  
                for(int k=0;k<3;++k)  
                {  
                    tp.mat[i][k]+=(a.mat[i][j]*b.mat[j][k])%mod;  
                    tp.mat[i][k]%=mod;                
                }  
            }   
        }  
        return tp;  
    }  
};  
  
  
int slove(int n)  
{  
    matrix base={2,1,0,2,2,2,0,1,2},ans={0};  
    for(int i=0;i<3;++i)  
    {  
        ans.mat[i][i]=1;  
    }  
    while(n)  
    {  
        if(n&1)  
        {  
            ans=ans*base;  
        }  
        base=base*base;  
        n>>=1;  
    }  
    return ans.mat[0][0];  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        int n;  
        scanf("%d",&n);  
        printf("%d\n",slove(n));  
    }  
    return 0;  
} 