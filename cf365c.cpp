#include <iostream>
#include <stdio.h>
using namespace std;

char str[20];
int main()
{
    int flag=0;
    int cou=1;
    int cnt=1;
    puts("2");
    fflush(stdout);

    while(cou<20)
    {
        cou++;
        scanf("%s",str);
        if(str[0]=='y')  {flag=1;cnt++;break;}
        else if(str[0]=='n')
        {
            if(cou==2) puts("89"),fflush(stdout);
         else if(cou==3) puts("83"),fflush(stdout);
         else if(cou==4) puts("79"),fflush(stdout);
         else if(cou==5) puts("73"),fflush(stdout);
         //2 3 5 7 11 13 17 19 23 29 31 37 41
//43 47 53 59 61 67 71 73 79 83 89 97
         else if(cou==6) puts("71"),fflush(stdout);
         else if(cou==7) puts("67"),fflush(stdout);
         else if(cou==8) puts("61"),fflush(stdout);
         else if(cou==9) puts("59"),fflush(stdout);
         else if(cou==10) puts("53"),fflush(stdout);
         else if(cou==11) puts("47"),fflush(stdout);
         else if(cou==12) puts("43"),fflush(stdout);
         else if(cou==13) puts("41"),fflush(stdout);
         else if(cou==14) puts("37"),fflush(stdout);
         else if(cou==15)   puts("31"),fflush(stdout);
         else if(cou==16) puts("29"),fflush(stdout);
         else if(cou==17) puts("23"),fflush(stdout);
         else if(cou==18) puts("19"),fflush(stdout);
         else if(cou==19) puts("17"),fflush(stdout);
         else if(cou==20) puts("13"),fflush(stdout);
         if(cou==20) break;
        }
    }
    if(!flag&&cou==20) puts("composite"),fflush(stdout);
    else if(flag==1) puts("prime"),fflush(stdout);


    return 0;
}
