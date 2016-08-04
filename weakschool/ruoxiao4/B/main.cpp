#include <iostream>
#include <stdio.h>
using namespace std;

int n, item[56];


int main()
{

    for (int i = 0; i < 26; i++)
        item[i] = 'a'+i;
    for (int i = 26; i < 52; i++)
        item[i] = 'A'+i-26;

    while (scanf("%d", &n) != EOF)
    {
        printf("2 %d %d\n", n, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", item[j]);
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < n; i++)
            {
            for (int j = 0; j < n; j++)
                printf("%c", item[i]);
            printf("\n");
            }
    }
    return 0;
}
