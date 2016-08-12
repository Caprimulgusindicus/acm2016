# include <stdio.h>
# include <string.h>

# define R 0x7
# define S 0x3
# define N 17

char tree[0x1<<(N-2)];
int a[100005];

void set_bit(int x)
{
    tree[x>>S] |= 0x1<<(x & R);
}

void clr_bit(int x)　　　　　　　　　　/* 这个函数实际上没用到，因为初始化是用memset()做的 */
{
    tree[x>>S] |= ~(0x1<<(x & R));
}

char get_bit(int x)
{
    return (char)((tree[x>>S]>>(x & R)) & 0x1);
}

int xor_max(int x)
{
    int i, k;
    
    k = 1;
    for (i = N-1; i >= 0; --i)
    {
        k <<= 1;
        if ((x>>i) & 0x1)
        {
            if (!get_bit(k)) k |= 0x1;
        }
        else
        {
            k |= 0x1;
            if (!get_bit(k)) k &= (~0x1);
        }
    }
    k -= (0x1<<N);
    
    return (k ^ x);
}

void pre_process(int x)
{
    int i;
    
    x += (0x1<<N);
    for (i = 0; i < N; ++i)
    {
        set_bit((x>>i));
    }
}

int max(int x, int y)
{
    return x>y? x:y;
}

int main()
{
    int n, i, ans;
        
    while (~scanf("%d", &n))
    {
        memset(tree, 0, sizeof(tree));　　　　/* 这里应该相对耗时较多，本来想通过初始化节点1和2，最后发现不行，WA */
        
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            pre_process(a[i]);
        }
        
        ans = 0;
        for (i = 0; i < n; ++i)
        {
            ans = max(ans, xor_max(a[i]));
        }
        
        printf("%d\n", ans);
    }

    return 0;
}