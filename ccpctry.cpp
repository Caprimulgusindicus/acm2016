#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    map<long long, int> ma;
    for (long long i = 2; i*i <= n; i++)
    {
        while (n%i==0)
        {
            ma[i]++;
            n /= i;
        }
    }
    if (n != (long long)1)
        ma[n]++;

    map<long long, int>::iterator it = ma.begin();
    for (; it != ma.end(); it++)
    {
        
        cout << it->first << ' ' << it->second << endl;
    }
    return 0;
}