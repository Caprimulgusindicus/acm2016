#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const char dirr[7][33]={"ChristopherNolan", "JohnWoo", "StevenSpielberg", "JamesCameron", "AnLee"};
const char arti[7][33]={"JenniferLawrence","EmmaWatson","ChristianBale","AnneHathaway","MattDamon","TomCruise"};
struct node
{
    char name[33];
    char dir[33];
    char art[33];
    int xad;
    int flagc;
    int vis;
};
//导演 C, Jo, S, Ja, A
//演员 J，E，C，A，M，T
node mov[23];

char ser[33][10];
int num[33];
bool cmp(node a,node b)
{
    int n=strcmp(a.name,b.name);
    int d=strcmp(a.dir,b.dir);
    int aa=strcmp(a.art,b.art);
    if(n==0)
    {
        if(!d) return aa<0;
        else return d<0;
    }
    else return n<0;
}

int main()
{
    int n;

   //freopen("1.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        memset(mov,0,sizeof(mov));
        int flagc;//系列flag
        for(int i=1;i<=n;i++)
        {
            scanf("%s %s %s",mov[i].name,mov[i].dir,mov[i].art);
        }
        sort(mov+1,mov+1+n,cmp);
 int cnt=1;
    int lalala=0;
    bool flag=0;

for(int i=1;i<=n;i++)
        {
        int aaa=mov[i].name[strlen(mov[i].name)-1]-'0';
        if(aaa==cnt)
        {
            if(!flag) {lalala++;flag=1;}
            num[i]=lalala;
            cnt++;
        }
        else
        {if(aaa==1) {num[i]=++lalala;cnt=2;}
        else {cnt=1;flag=0;}
        }
        }


    for(int i=1;i<=n;i++)
        {
             for(int j=0;j<5;j++)
                if(strcmp(mov[i].dir,dirr[j])==0) mov[i].xad++;

           for(int j=0;j<6;j++)
                if(strcmp(mov[i].art,arti[j])==0) mov[i].xad++;

            int len=strlen(mov[i].name);
            //cout<<mov[i].name[len-1]<<" ";
            if(mov[i].name[len-1]>48&&mov[i].name[len-1]<=57) mov[i].flagc++;

        }



        for(int k=lalala;k>0;k--)
        {
            int ma=0;
            for(int i=1;i<=n;i++)
                if(num[i]==k)
                    ma=ma>mov[i].xad?ma:mov[i].xad;
            for(int i=1;i<=n;i++)
                if(num[i]==k)
                    mov[i].xad=ma;
        }


        for(int i=1;i<=n;i++)
            if(mov[i].xad==2&&!mov[i].vis)
                cout<<mov[i].name<<endl;
                //" "<<mov[i].xad<<" "<<mov[i].flagc<<endl;

        for(int i=1;i<=n;i++)
            if(mov[i].xad==1&&!mov[i].vis)
                cout<<mov[i].name<<endl;
                //" "<<mov[i].xad<<" "<<mov[i].flagc<<endl;

        for(int i=1;i<=n;i++)
            if(mov[i].xad==0&&!mov[i].vis)
                cout<<mov[i].name<<endl;
                //<<" "<<mov[i].xad<<" "<<mov[i].flagc<<endl;

}
    return 0;
}
