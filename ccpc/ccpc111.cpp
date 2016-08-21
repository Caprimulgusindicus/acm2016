#include <cstdio>
#include <iostream>
#include <cstring>
 using namespace std;
 char num[100000005];
 int ca=1;
 int main()
 {


 while(scanf("%s",num) != EOF)
    {
        int len = strlen(num);
        long long ans = 0;
        for(int i = 0; i < len; ++i)
        {
            ans = ans*10 + (num[i]-'0');
            ans %= 10001;
        }
        printf("Case #%d: ",ca);
        if(ans==0) printf("YES\n");
        else printf("NO\n");
        ca++;
    }
}