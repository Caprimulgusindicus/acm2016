// -bash-3.2$ more prime.c
 
/*
 *      100             25
 *      1000            168
 *      1000,0          1229
 *      1000,00         9592
 *      1000,000        78498
 *      1000,000,0      664579
 *      1000,000,00     5761455
 *      1000,000,000    54316419
*/
 
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
 
#define  E9        2000000
#define  E10       10000000000
#define  E11       100000000000
#define  E12       1000000000000
 
char table[E9];
int num = 0;
//int prime[E8];
 
void cal_table()
{
        long long sum=0;
        int j, k;
        time_t t1, t2;
        t1 = time(NULL);
        memset(table, 1, E9);
        for (j = 2 ; j < E9; j++) {
                if ( table[j] ) {
                        num++;
                        sum+=j;
                        for ( k = j + j; k < E9; k += j )
                        {
                                table[k] = 0;
                        }
                }
                
        }

        t2 = time(NULL);
        cout<<sum<<endl;
        printf("Totaly %d primes until E9, cost %d time_t.\n", num, t2 - t1);
}
 
int main()
{
    int i;
    cal_table();
    //init_prime();
    return 0;
}