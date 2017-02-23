#include <cstdio>
#include <cstring>

using namespace std;

char buff[8];

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d%s", &x, buff);
        if (strcmp(buff, "South") == 0)
        {
            sum += x;
        }
        else if (strcmp(buff, "North") == 0)
        {
            sum -= x;
        }
        else if ((sum == 0) || (sum == 20000))
        {
            printf("NO\n");
            return 0;
        }
        if ((sum < 0) || (sum > 20000))
        {
            printf("NO\n");
            return 0;
        }
    }
    if (sum != 0)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES");
    }
    return 0;
}
