
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000007
typedef long long LL;
template <typename T> class Matrix{
    public:
    int n,m ;
    T a[33][33];
    Matrix() {memset(a , 0 , sizeof(a));}
    Matrix(int _n , int _m) {
        n = _n , m = _m , memset(a , 0 , sizeof(a));
    };
    T* operator[] (int i) {return a[i];}
    Matrix friend operator * (Matrix A , Matrix B){
        Matrix ans(A.n , B.m);
        for (int i = 0 ; i < A.n ; ++ i)
            for (int j = 0 ; j < A.m ; ++ j)if(A[i][j]!=0)
                for (int k = 0 ; k < B.m ; ++ k)
                    ans[i][k]=(ans[i][k]+A[i][j]*B[j][k])%MOD;
        return ans;
    }
};

int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        Matrix <LL> E,A;
	    int n,m,k;
	    scanf("%d%d%d",&n,&m,&k);
	    E.n=E.m=A.n=A.m=(m+1)*2;

	    for(int i=0;i<E.n;i++)
	    	E[i][i]=1;

	    for(int i=0;i<m+1;i++)
	    	for(int j=0;j<2;j++)
	    		for(int p=0;p<k;p++)
	    			for(int q=0;q<k;q++)
	    			{
	        			int fi=(p==q)?i+1:0,fj=j;
	        			if(fi<=m)
	        			{
	            		fj|=fi==m;
	            		A[i*2+j][fi*2+fj]++;
	        		}
	    }
	    while(n)
	    {
	        if(n&1)E=A*E;
	        A=A*A;
	        n>>=1;
	    }

	    LL ans=0;
	    for(int i=0;i<m+1;i++)
	    	ans+=E[0][i*2+1];
	    ans%=MOD;

	    printf("%lld\n",ans);
    }
    return 0;
}