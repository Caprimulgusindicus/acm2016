#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[11111];
bool ok[11111];

int main() {
    
    freopen("blar.in", "r", stdin);
    freopen("outlarb.txt","w",stdout);
    int T, ansk = 0;
    scanf("%d", &T);
    while(T--) 
    {
        scanf("%s", s + 1);
        printf("Case #%d: ", ++ansk);

        int len = strlen(s + 1);
        ok[1] = 1;
        for(int i = 2; i <= len; i++) 
        {
            if(ok[i - 1] && s[i - 1] <= s[i]) ok[i] = 1;
            else ok[i] = 0;
        }

        if(ok[len]) 
        {
            printf("%s\n", s + 1);
            continue;
        }
        s[0] = '0';

        bool flag = false;
        for(int p = len - 1; p >= 1; p--) 
        {
            if(s[p] > '0' && s[p] - 1 >= s[p - 1]) 
            {
                for(int i = 1; i < p; i++) printf("%c", s[i]);
                if(p != 1 || s[p] - 1 != '0') printf("%c", s[p] - 1);
                for(int i = p + 1; i <= len; i++) printf("9");
                flag = true; break;
            }
        }
        printf("\n");
    }
    return 0;
}