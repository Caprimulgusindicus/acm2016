#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct point
{
    int x;
    int y;
} ;
point p[5];

int sq(int x)
{
    return x*x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int ca;
    while(~scanf("%d",&ca))
    {
        for(int c=1;c<=ca;c++)
        {
            int flag=0;
        for(int i=1;i<=4;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            //cout<<p[i].x<<" "<<p[i].y<<endl<<endl;
        }

        //cout<<sq(p[1].x-p[4].x)+sq(p[1].y-p[4].y)<<endl;
        //cout<<sq(p[3].x-p[2].x)+sq(p[3].y-p[2].y)<<endl;
        //cout<<sq(p[1].x-p[2].x)+sq(p[1].y-p[2].y)<<endl;
        //cout<<sq(p[3].x-p[4].x)+sq(p[3].y-p[4].y)<<endl;

        if(sq(p[1].x-p[4].x)+sq(p[1].y-p[4].y)==sq(p[3].x-p[2].x)+sq(p[3].y-p[2].y)
        &&(sq(p[1].x-p[2].x)+sq(p[1].y-p[2].y)==sq(p[3].x-p[4].x)+sq(p[3].y-p[4].y)))
        {
                flag=1;
                if((p[2].x-p[1].x)*(p[2].x-p[3].x)==(p[2].y-p[1].y)*(p[3].y-p[2].y))
                {
                    if(sq(p[1].x-p[2].x)+sq(p[1].y-p[2].y)==sq(p[2].x-p[3].x)+sq(p[2].y-p[3].y))
                        flag=4;
                    else  flag=2;
                }
                else if(sq(p[1].x-p[2].x)+sq(p[1].y-p[2].y)==sq(p[2].x-p[3].x)+sq(p[2].y-p[3].y))
                    flag=3;
        }
        else flag=5;

        printf("Case #%d: ",c);
        if(flag==1) printf("Parallelogram\n");
        if(flag==2) printf("Rectangle\n");
        if(flag==3) printf("Diamond\n");
        if(flag==4) printf("Square\n");
        if(flag==5) printf("Others\n");

        }

    }
    return 0;
}
