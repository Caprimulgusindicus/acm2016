#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;
#define EP 1e-8

struct point{    //��
    double x, y;
}p[20];

struct trangle{    //�����Σ�������2���ǵ�(����ֵ*2)��
    double A, B;
}tra[10005];

bool mat[205][205], vis[10005];

double dist (point a, point b)    //ŷʽ������߳�
{
    return sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

bool multi (point a, point b, point c)    //����ж������Ƿ���
{
    double x1, y1, x2, y2;
    x1 = b.x - a.x;
    y1 = b.y - a.y;
    x2 = c.x - b.x;
    y2 = c.y - b.y;
    int tp = x1 * y2 - x2 * y1;
    if (tp == 0)
        return false;
    return true;
}

bool similar (trangle a, trangle b)        //����ֵ��Ӧ�Ƚ��ж�����,2���Ǽ���
{
    if (fabs (a.A-b.A) <= EP && fabs (a.B-b.B) <= EP)
        return true;
    return false;
}

int main()
{
    double e[3];
    int n, i, j, k, num, tp, maxs;
    while (scanf ("%d", &n), n)
    {
        memset (mat, false, sizeof(mat));
        for (i = 0; i < n; i++)
        {
            scanf ("%lf%lf", &p[i].x, &p[i].y);
            if (mat[(int)p[i].x+100][(int)p[i].y+100])    //���ֹ��ĵ�Ͳ���Ҫ��
                i--, n--;
            mat[(int)p[i].x+100][(int)p[i].y+100] = true;
        }
        num = 0;    //�ۼƺϷ������θ���
        for (i = 0; i < n; i++)    //��ȡ���кϷ������δ�ŵ�tra
        {
            for (j = i + 1; j < n; j++)
            {
                for (k = j + 1; k < n; k++)
                {
                    if (!multi (p[i], p[j], p[k]))    //�ж������κϷ���
                        continue;
                    e[0] = dist (p[i], p[j]);
                    e[1] = dist (p[i], p[k]);
                    e[2] = dist (p[j], p[k]);
                    sort (e, e+3);        //��������ʵ�ֶ�Ӧ�Ƚ�
                    double a = e[0];
                    double b = e[1];
                    double c = e[2];
                    tra[num].A = (b*b + c*c - a*a)/b/c; //ֱ����(����ֵ*2)��Ӧ�ж�
                    tra[num].B = (a*a + c*c - b*b)/a/c;
                    num++;
                }
            }
        }
        maxs = 0;
        memset (vis, false, sizeof(vis));
        for (i = 0; i < num; i++)    //��һ��������Ϊ��׼���±Ƚ�������������
        {
            if (vis[i])        //�Ѿ����ʹ��ľͲ���������Ϊ׼��
                continue;
            tp = 1;
            for (j = i + 1; j < num; j++)
            {
                if (vis[j])
                    continue;
                if (similar (tra[i], tra[j]))
                    tp++, vis[j] = true;
            }
            if (tp > maxs)
                maxs = tp;
        }
        printf ("%d\n", maxs);
    }
}
