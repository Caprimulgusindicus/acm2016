#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <string>
#include <algorithm>
const int MAXN=233333333;
using namespace std;

int n;
int f[100001][2];
int a[100001];

string s[100001];

string rev(string s){
    string ret=s;
    reverse(ret.begin(), ret.end());
    return ret;
}
void init(){
    for(int i=0;i<=100000;i++){
        for(int j=0;j<=1;j++){
            f[i][j]=MAXN;
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    init();
    f[1][0]=0;
    f[1][1]=a[1];
    for(int i=2;i<=n;i++){
        if(s[i]>=s[i-1] && s[i]>=rev(s[i-1])){
            f[i][0]=min(f[i-1][0],f[i-1][1]);
            f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
        }else if(s[i]>=s[i-1] && s[i]<rev(s[i-1])){
            if(rev(s[i])>=s[i-1]){
                f[i][0]=f[i-1][0];
                f[i][1]=f[i-1][0]+a[i];
            }else{
                f[i][0]=f[i-1][0];
                f[i][1]=min(f[i-1][0],f[i-1][i])+a[i];
            }
        }else if(s[i]<s[i-1] && s[i]>=rev(s[i-1])){
            if(rev(s[i])>=s[i-1]){
                f[i][0]=f[i-1][1];
                f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
            }
        }else{
            if(s[i]<s[i-1] && s[i]<rev(s[i-1])){
                
            }
        }
    }
    int ans=min(f[n][0],f[n][1]);
    if(ans==MAXN){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}