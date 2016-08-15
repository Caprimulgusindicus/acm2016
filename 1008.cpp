#include<cstdio>
int x[200],y[200],z[200];
int ok(int i,int j,int k,int l){
    int ij[3]={x[j]-x[i],y[j]-y[i],z[j]-z[i]};
    int kl[3]={x[l]-x[k],y[l]-y[k],z[l]-z[k]};
    int ijkl[3]={x[k]+x[l]-x[i]-x[j],y[k]+y[l]-y[i]-y[j],z[k]+z[l]-z[i]-z[j]};
    if(ijkl[0]==0&&ijkl[1]==0&&ijkl[2]==0)return 0;
    if(ij[0]*kl[0]+ij[1]*kl[1]+ij[2]*kl[2]!=0)return 0;
    if(ij[0]*ijkl[0]+ij[1]*ijkl[1]+ij[2]*ijkl[2]!=0)return 0;
    if(kl[0]*ijkl[0]+kl[1]*ijkl[1]+kl[2]*ijkl[2]!=0)return 0;
    return 1;
} 
int main(){
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        int N,n;
        scanf("%d",&N);
        for(n=0;n<N;n++)
            scanf("%d%d%d",&x[n],&y[n],&z[n]);
        int i,j,k,l,ans=0;
        for(i=0;i<N-3;i++)
            for(j=i+1;j<N-2;j++)
                for(k=j+1;k<N-1;k++)
                {
                    int ij=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])+(z[j]-z[i])*(z[j]-z[i]);
                    int ik=(x[k]-x[i])*(x[k]-x[i])+(y[k]-y[i])*(y[k]-y[i])+(z[k]-z[i])*(z[k]-z[i]);
                    int jk=(x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j])+(z[k]-z[j])*(z[k]-z[j]);
                    if(ij!=ik&&ij!=jk&&ik!=jk)continue;
                    for(l=k+1;l<N;l++)
                        if(ok(i,j,k,l))ans++;
                        else if(ok(i,k,j,l))ans++;
                        else if(ok(i,l,j,k))ans++;
                }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}