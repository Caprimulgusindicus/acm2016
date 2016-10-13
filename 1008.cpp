#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=110000;
long long A[N<<2],num[N<<2],mi[N<<2],ma[N<<2],B[N<<2];
int n,m,size[N<<2];
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if (p1==pend){
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if (pend==p1){IOerror=1;return -1;}
            //{printf("IO error!\n");system("pause");for (;;);exit(0);}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    inline void read(int &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(ll &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (sign)x=-x;
    }
    inline void read(double &x){
        bool sign=0; char ch=nc(); x=0;
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        if (ch=='-')sign=1,ch=nc();
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
        if (ch=='.'){
            double tmp=1; ch=nc();
            for (;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
        }
        if (sign)x=-x;
    }
    inline void read(char *s){
        char ch=nc();
        for (;blank(ch);ch=nc());
        if (IOerror)return;
        for (;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
        *s=0;
    }
    inline void read(char &c){
        for (c=nc();blank(c);c=nc());
        if (IOerror){c=-1;return;}
    }
    //getchar->read
    inline void read1(int &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(ll &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (bo)x=-x;
    }
    inline void read1(double &x){
        char ch;int bo=0;x=0;
        for (ch=getchar();ch<'0'||ch>'9';ch=getchar())if (ch=='-')bo=1;
        for (;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
        if (ch=='.'){
            double tmp=1;
            for (ch=getchar();ch>='0'&&ch<='9';tmp/=10.0,x+=tmp*(ch-'0'),ch=getchar());
        }
        if (bo)x=-x;
    }
    inline void read1(char *s){
        char ch=getchar();
        for (;blank(ch);ch=getchar());
        for (;!blank(ch);ch=getchar())*s++=ch;
        *s=0;
    }
    inline void read1(char &c){for (c=getchar();blank(c);c=getchar());}
    //scanf->read
    inline void read2(int &x){scanf("%d",&x);}
    inline void read2(ll &x){
        #ifdef _WIN32
            scanf("%I64d",&x);
        #else
        #ifdef __linux
            scanf("%lld",&x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void read2(double &x){scanf("%lf",&x);}
    inline void read2(char *s){scanf("%s",s);}
    inline void read2(char &c){scanf(" %c",&c);}
    inline void readln2(char *s){gets(s);}
    //fwrite->write
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
        void out(char ch){
            if (p1==pend){
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf;
            }
            *p1++=ch;
        }
        void print(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(int x){
            static char s[15],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void println(ll x){
            static char s[25],*s1;s1=s;
            if (!x)*s1++='0';if (x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1); out('\n');
        }
        void print(double x,int y){
            static ll mul[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,
                1000000000,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
                100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if (x<-1e-12)out('-'),x=-x;x*=mul[y];
            ll x1=(ll)floor(x); if (x-floor(x)>=0.5)++x1;
            ll x2=x1/mul[y],x3=x1-x2*mul[y]; print(x2);
            if (y>0){out('.'); for (size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i); print(x3);}
        }
        void println(double x,int y){print(x,y);out('\n');}
        void print(char *s){while (*s)out(*s++);}
        void println(char *s){while (*s)out(*s++);out('\n');}
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    inline void print(int x){Ostream.print(x);}
    inline void println(int x){Ostream.println(x);}
    inline void print(char x){Ostream.out(x);}
    inline void println(char x){Ostream.out(x);Ostream.out('\n');}
    inline void print(ll x){Ostream.print(x);}
    inline void println(ll x){Ostream.println(x);}
    inline void print(double x,int y){Ostream.print(x,y);}
    inline void println(double x,int y){Ostream.println(x,y);}
    inline void print(char *s){Ostream.print(s);}
    inline void println(char *s){Ostream.println(s);}
    inline void println(){Ostream.out('\n');}
    inline void flush(){Ostream.flush();}
    //puts->write
    char Out[OUT_SIZE],*o=Out;
    inline void print1(int x){
        static char buf[15];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(int x){print1(x);*o++='\n';}
    inline void print1(ll x){
        static char buf[25];
        char *p1=buf;if (!x)*p1++='0';if (x<0)*o++='-',x=-x;
        while(x)*p1++=x%10+'0',x/=10;
        while(p1--!=buf)*o++=*p1;
    }
    inline void println1(ll x){print1(x);*o++='\n';}
    inline void print1(char c){*o++=c;}
    inline void println1(char c){*o++=c;*o++='\n';}
    inline void print1(char *s){while (*s)*o++=*s++;}
    inline void println1(char *s){print1(s);*o++='\n';}
    inline void println1(){*o++='\n';}
    inline void flush1(){if (o!=Out){if (*(o-1)=='\n')*--o=0;puts(Out);}}
    struct puts_write{
        ~puts_write(){flush1();}
    }_puts;
    inline void print2(int x){printf("%d",x);}
    inline void println2(int x){printf("%d\n",x);}
    inline void print2(char x){printf("%c",x);}
    inline void println2(char x){printf("%c\n",x);}
    inline void print2(ll x){
        #ifdef _WIN32
            printf("%I64d",x);
        #else
        #ifdef __linux
            printf("%lld",x);
        #else
            puts("error:can't recognize the system!");
        #endif
        #endif
    }
    inline void println2(ll x){print2(x);printf("\n");}
    inline void println2(){printf("\n");}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
void add(int k1,long long k2){
	if (B[k1]!=-1) B[k1]+=k2; else A[k1]+=k2; 
	num[k1]+=k2*size[k1]; mi[k1]+=k2; ma[k1]+=k2;
}
void change(int k1,long long k2){
	A[k1]=0; B[k1]=k2; num[k1]=k2*size[k1]; mi[k1]=k2; ma[k1]=k2;
}
int k4,k5;
long long k6;
int sq[10000010];
const int NN=10000000;
void pushdown(int k1){
	if (B[k1]!=-1){
		change(k1*2,B[k1]); change(k1*2+1,B[k1]); B[k1]=-1;
	} else 
	if (A[k1]){
		add(k1*2,A[k1]); add(k1*2+1,A[k1]); A[k1]=0;
	}
}
void change(int k1){
	int l=k1*2,r=k1*2+1;
	num[k1]=num[l]+num[r];
	mi[k1]=min(mi[l],mi[r]);
	ma[k1]=max(ma[l],ma[r]);
}
void buildtree(int k1,int k2,int k3){
	A[k1]=0; B[k1]=-1; size[k1]=k3-k2+1;
	if (k2==k3){
		read(num[k1]); mi[k1]=num[k1]; ma[k1]=num[k1];
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid); buildtree(k1*2+1,mid+1,k3);
	change(k1);
}
long long nowmi,nowma;
void add(int k1,int k2,int k3){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		//cout<<"add "<<k1<<" "<<k2<<" "<<k3<<" "<<k6<<endl;
		add(k1,k6); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	if (mid>=k4) add(k1*2,k2,mid);
	if (mid<k5) add(k1*2+1,mid+1,k3);
	change(k1);
}
long long find(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return 0;
	if (k2>=k4&&k3<=k5) return num[k1];
	int mid=k2+k3>>1; pushdown(k1);
	return find(k1*2,k2,mid,k4,k5)+find(k1*2+1,mid+1,k3,k4,k5);
}
int check(long long k1,long long k2){
	k1=min(k1,nowmi); k2=max(k2,nowma);
	if (k2-k1>1) return 0;
	nowmi=k1; nowma=k2; return 1;
}
long long getsqrt(long long k1){
	if (k1<=N) return sq[k1];
	return trunc(sqrt(k1)+1e-8);
}
int tot=0;
void changein(int k1){
	long long k2=getsqrt(mi[k1]);
	if (mi[k1]==ma[k1]) change(k1,k2);
	else {
		long long k3=getsqrt(ma[k1]);
		if (k2==k3) change(k1,k2);
		else add(k1,k2-mi[k1]);
	}
}
void changeall(int k1,int k2,int k3){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5&&ma[k1]-mi[k1]<=1) {changein(k1); return;}
	int mid=k2+k3>>1; pushdown(k1);
	if (mid>=k4) changeall(k1*2,k2,mid);
	if (mid<k5) changeall(k1*2+1,mid+1,k3);
	change(k1);
}
void change2(int l,int r){
	k4=l; k5=r;
	changeall(1,1,n); return;
}
void solve(){ tot=0;
	read(n); read(m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; read(k1); read(k2); read(k3);
		if (k1==1){
			int k7; read(k7); k4=k2; k5=k3; k6=k7; add(1,1,n);
		} else if (k1==2) change2(k2,k3);
		else println(find(1,1,n,k2,k3));
	}
	//cerr<<tot<<endl;
}
int main(){
	for (int i=1;i*i<=NN;i++){
		int l=i*i,r=min(NN,(i+1)*(i+1)-1);
		for (int j=l;j<=r;j++) sq[j]=i;
	}
	//freopen("data.in","r",stdin);
	//freopen("data1.out","w",stdout);
	int t; read(t);
	for (;t;t--) solve();
	return 0;
}
