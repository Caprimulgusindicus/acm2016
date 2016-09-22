/******************************************************************
copyright (C) 2007 Huang Yuanbing
version 1.1, 2007 PrimeNumber
mailto: bailuzhou@163.com1 (remove the last digit 1 for "laji" mail)
free use for non-commercial purposes
******************************************************************

  main ideal come from a paper by M.DELEGLISE ADN J.LAGARIAS
  "COMPUTING PI(x): THE MEISSEL, LEHMER, LAGARIAS, MILLER, ODLYZKO METHOD"

  a = PI(y); (y >>= x^(1/3) and y <= x^(1/2))

  PI(x)         = phi(x, a) + a - 1 - P2Xa(x,a);
  phi(x, a)     = S0 + S
  = S0  + S1 + S3 + S2
  = S0  + S1 + S3 + U + V
  = S0  + S1 + S3 + U + V1 + V2
  = S0  + S1 + S3 + U + V1 + W1 + W2 + W3 + W4 + W5
  it need O(n^2/3) space and MAXN > 10 and MAXN <= 1e11
**********************************************************************/

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <assert.h>

#define COMP 4
#define MASKN(n)  (1 << ((n >> 1) & 7))
#define min(a, b) (a) < (b) ? (a) : (b)
#define MULTI_THREAD
#define THRED_NUMS 4
//#define PRINT_DEBUG

typedef unsigned int uint;
#ifdef _WIN32
typedef  __int64 int64;
#else
typedef long long int64;
#endif

int *Prime;
int *PI;

int64 MAXN = (int64)1e11;
int pt[130000];   // MAXN < 1e11, size = np

int *phiTable;
int *minfactor;

int x23, x12, x13, x14, y;
int64 x;

int ST = 7, Q = 1, phiQ = 1;
//Q    = 2*3*5*7*11*13 = 30030
//phiQ = 1*2*4*6*10*12 = 5760

int phi(int x, int a)
{
    if (a == ST)
        return (x / Q) * phiQ + phiTable[x % Q];
    else if (a == 0)
        return x;
    else if (x < Prime[a])
        return 1;
    else
        return phi(x, a - 1) - phi(x / Prime[a], a - 1);
}

#ifdef MULTI_THREAD
struct ThreadInfo{
    int pindex;
    int theadnums;
    int64 pnums;
}Threadparam[2 * THRED_NUMS + 2];

#ifdef _WIN32
#include <windows.h>
DWORD WINAPI WIN32ThreadFun(LPVOID pinfo)
#else
#include <pthread.h>
void* POSIXThreadFun(void *pinfo)
#endif
{
    ThreadInfo *pThreadInfo = (ThreadInfo *) (pinfo);
    int addstep = pThreadInfo->theadnums * 2;

    for (int i = pThreadInfo->pindex; pt[i] != 0; i += addstep){
        if (pt[i] > 0)
            pThreadInfo->pnums -= phi(pt[i], pt[i + 1]);
        else
            pThreadInfo->pnums += phi(-pt[i], pt[i + 1]);
    }
    //    printf("ThreadID = %4d, phi(%d) = %d\n", GetCurrentThreadId(), pThreadInfo->pindex, pThreadInfo->pnums);
    //    printf("ThreadID = %4d, phi(%d) = %d\n", pthread_self(), pThreadInfo->pindex, pThreadInfo->pnums);
    return 0;
}

int64 multiThread(int theadnums)
{
    int i;
    int64 pnums = 0;

 assert(theadnums < 2 * THRED_NUMS);

    for (i = 0; i < theadnums; i++){
        Threadparam[i].pindex = 2 * i + 1;
        Threadparam[i].theadnums = theadnums;
        Threadparam[i].pnums  = 0;
    }

#ifdef _WIN32
    HANDLE tHand[THRED_NUMS * 2];
    DWORD threadID[THRED_NUMS * 2];
    for (i = 0; i < theadnums; i++){
        tHand[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)WIN32ThreadFun, (LPVOID)(&Threadparam[i]), 0, &threadID[i]);
        if (tHand[i] == NULL)
            printf("create Win32 thread error\n");
    }
    WaitForMultipleObjects(theadnums, tHand, true, INFINITE);
    for (i = 0; i < theadnums; i++){
        pnums += Threadparam[i].pnums;
        CloseHandle(tHand[i]);
    }
#else
    pthread_t tid[THRED_NUMS];
    for (i = 0; i < theadnums; i++){
        int    error = pthread_create(&tid[i], NULL, POSIXThreadFun, &Threadparam[i]);
        if ( error != 0 )
            printf("Create pthread error: %d\n", error);
    }
    for (i = 0; i < theadnums; i++){
        pthread_join(tid[i], NULL);
        pnums += Threadparam[i].pnums;
    }
#endif
    return pnums;
}
#endif

int freememory(int alloc)
{
    int memsize = (x / y) + 100;
    if (alloc == 0){
        int psize = (int) (memsize / log(memsize));
        //printf("psize = %d memeszie = %d\n", psize, (int)(psize * 1.2) );
        PI = new int [memsize + 100];
        Prime = new int[(int)(psize * 1.2) + 100];
        assert(PI && Prime);
    }else{
        delete phiTable;
        delete minfactor;
        delete Prime;
        delete PI;
    }
    return alloc;
}

void init_phiTable( )
{
    clock_t start = clock();

    int p, i, j;

    if (x < 1e10)
        ST = 6;
    if (ST > PI[y])
        ST = PI[y];

    for (i = 1; i <= ST; ++i){
        Q *= Prime[i];
        phiQ *= Prime[i] - 1;
    }

    phiTable = new int[Q + 10];
    for (i = 0; i < Q; ++i)
        phiTable[i] = i;

    for (i = 1; i <= ST; ++i){
        p = Prime[i];
        for (j = Q - 1; j >= 0; --j)
            phiTable[j] -= phiTable[j / p];
    }

    printf("    Q = %d, PhiQ = %d\n", Q, phiQ);
    printf("    init_phiTable time = %ld ms\n", clock() - start);
}

void init_minFactor( )
{
    clock_t start = clock();

    int i, j, maxy = y + 10;
    int sqrty = (int)sqrt(maxy) + 1;

    minfactor = new int[maxy + 10];
    for (i = 0; i < maxy; i++)
        minfactor[i] = i;

    for (i = 1; Prime[i] <= maxy; i++){
        for (j = Prime[i]; j <= maxy; j += Prime[i]){
            if (minfactor[j] == -j || minfactor[j] == j)
                minfactor[j] = -Prime[i];
            else
                minfactor[j] = -minfactor[j];
        }
    }

    for (i = 1; Prime[i] <= sqrty; i++){
        int powp = Prime[i] * Prime[i];
        for (j = powp; j <= maxy; j += powp)
            minfactor[j] = 0;
    }
    printf("    init_minFactor time = %ld ms\n", clock() - start);
}

int sieve( )
{
    clock_t start = clock();

    int primes = 1;
    int maxp = (x / y) + 10;
    Prime[1] = 2;

    unsigned char *bitMask = (unsigned char *) PI;
    memset(bitMask, 0, (maxp + 64) >> COMP);

    for (int p = 3; p < maxp; p += 2){
        if ( !(bitMask[p >> COMP] & MASKN(p)) ){
            Prime[++primes] = p;
            if (p > maxp / p)
                continue;
            for (int j = p * p; j < maxp; j += p << 1)
                bitMask[j >> COMP] |= MASKN(j);
        }
    }

    Prime[0] = primes;
    Prime[primes] = 0;
    printf("pi(%d) = %d\n", maxp, primes);

    printf("    sieve time = %ld ms\n", clock() - start);
    return primes;
}

void init_x( )
{
    x = (int64)MAXN;
    x23 = (int)(pow(x, 2.0 / 3) + 0.01);
    x12 = (int)(pow(x, 1.0 / 2) + 0.01);
    x13 = (int)(pow(x, 1.0 / 3) + 0.01);
    x14 = (int)(pow(x, 1.0 / 4) + 0.01);

    assert((int64)x12 * x12 <= x);
    assert((int64)x13 * x13 * x13 <= x);
    assert((int64)x14 * x14 * x14 * x14 <= x);

    y = x13;

    printf("    x14 = %d, x13 = %d, x12 = %d x23 = %d, y = %d\n", x14, x13, x12, x23, y);

    freememory(0);
}

int64 cal_S0( )
{
    int64 S0 = x;
    for (int j = 2; j <= y; j++){
        if (minfactor[j] > 0)
            S0 += x / j;
        else if (minfactor[j] < 0)
            S0 -= x / j;
    }

    printf("S0 = %lld\n", S0);

    return S0;
}

// so bad performance in this function
int64 cal_S3( )
{
    clock_t start = clock();

    int i, p, a;
    int np = 1;
    int64 S3 = 0;

    for (i = 1; i <= PI[x14]; i++){
        p = Prime[i];
        a = PI[p] - 1;
#ifdef PRINT_DEBUG
        assert(p <= x14 && a >= 0);
#endif
        for (int m = y / p + 1; m <= y; m++){
            int xx = x / (int64)(m * p);
#ifndef MULTI_THREAD
            if (minfactor[m] > p)
                S3 -= phi(xx, a);
            else if (minfactor[m] < -p)
                S3 += phi(xx, a);
#else
            if (minfactor[m] > p){
                pt[np++] = xx;
                pt[np++] = a;
            }
            else if (minfactor[m] < -p){
                pt[np++] = -xx;
                pt[np++] = a;
            }
#endif
        }
    }

#ifdef MULTI_THREAD
    printf("np = %d\n", np);
 if (np < 100)
  S3 = multiThread(1);
 else
  S3 = multiThread(THRED_NUMS);
#endif

    printf("S3 = %lld\n", S3);
    printf("    cal S3 time = %ld ms\n", clock() - start);
    return S3;
}

void init_PI( )
{
    clock_t start = clock();

    int Px = 1;
    PI[0] = PI[1] = 0;
    for (int i = 1; Prime[i]; i++, Px++){
        for (int j = Prime[i]; j <= Prime[i + 1]; j++)
            PI[j] = Px;
    }

    //printf("        Px = %d, primes = %d\n", Px, Prime[0]);
    printf("        PI[%d] = %d\n", Px, PI[Px - 1]);
    printf("    init_PI  time = %ld ms\n", clock() - start);
}

int64 cal_P2xa( )
{
    int64 phi2 = (int64)PI[y] * (PI[y] - 1) / 2 - (int64)PI[x12] * (PI[x12] - 1) / 2;

    for (int i = PI[y] + 1; i <= PI[x12] + 0; i++){
        int p = Prime[i];
#ifdef PRINT_DEBUG
        assert(p > y && p <= x12);
#endif
        phi2 += PI[x / p];
    }
    printf("P2xa(%lld, %d) = %lld\n", x, PI[y], phi2);

    return phi2;
}

int64 cal_S1( )
{
    int64 temp = PI[y] - PI[x13];
    int64 S1 = temp * (temp - 1) / 2;
    printf("S1 = %lld\n", S1);

    return S1;
}

int64 cal_U( )
{
    int64 p, U = 0;
    int sqrt_xdivy = (int)sqrt(x / y);
    for (int i = PI[sqrt_xdivy] + 1; i <= PI[x13]; i++){
        p = Prime[i];
        U += PI[y] - PI[x / (p * p)];
    }

    printf("U = %lld\n", U);

    return U;
}

int64 cal_V1( )
{
    int64 V1 = 0;
    int MINq, p;
    for (int i = PI[x14] + 1; i <= PI[x13]; i++){
        p = Prime[i];
        MINq = min((uint)y, x / ((int64)p * p));
#ifdef PRINT_DEBUG
        assert(p > x14 && p <= x13 && MINq >= p);
#endif
        V1 += (int64)(2 - PI[p]) * (PI[MINq] - PI[p]); //!!!!!!
    }

    printf("V1 = %lld\n", V1);

    return V1;
}

int64 cal_V2( )
{
    int64 V2 = 0;
    int i, sqrt_xdivy  = (int)sqrt(x / y);
    //    int sqrt_xdivy2 = (int)sqrt(x / (y * y));
    //    int sqrt_xdivp  = (int)sqrt(x / 1);
    int xdivy2 = x / (y * y);

#if 0
    uint p, q;
    uint W[6] = {0};
    //W1
    for (p = x14 + 1; p <= xdivy2; p++)
        for (q = p + 1; q <= y; q++)
            W[1] += PI[x / (p * q)];

    //W2
    for (p = xdivy2 + 1; p <= sqrt_xdivy; p++){
        sqrt_xdivp = (uint)sqrt(x / p);
        for (q = p + 1;  q <= sqrt_xdivp; q++)
            W[2] += PI[x / (p * q)];
    }

    //W3
    for (p = xdivy2 + 1; p <= sqrt_xdivy; p++)
        for (q = sqrt(x / p) + 1;  q <= y; q++)
            W[3] += PI[x / (p * q)];

    //W4
    for (p = sqrt_xdivy + 1; p <= x13; p++){
        sqrt_xdivp = (uint)sqrt(x / p);
        for (q = p; q <= sqrt_xdivp; q++)
            W[4] += PI[x / (p * q)];
    }

    //W5
    for (p = sqrt_xdivy + 1; p <= x13; p++)
        for (q = sqrt(x / p) + 1; q <= xdivy2; q++)
            W[5] += PI[x / (p * q)];
    V2 = W[1] + W[2] + W[3] + W[4] + W[5];

#else

    for (i = PI[x14] + 1; i <= PI[sqrt_xdivy]; i++){
        int64 p = Prime[i];
#ifdef PRINT_DEBUG
        assert(p > x14 && p <= sqrt_xdivy);
#endif
        for (int j = PI[p] + 1; j <= PI[y]; j++){
            int q = Prime[j];
#ifdef PRINT_DEBUG
            assert(q > p && q <= y);
#endif
            V2 += PI[x / (p * q)];
        }
    }

    for (i = PI[sqrt_xdivy] + 1; i <= PI[x13]; i++){
        int64 p = Prime[i];
#ifdef PRINT_DEBUG
        assert(p > sqrt_xdivy && p <= x13);
#endif
        xdivy2 = x / (p * p);
        for (int j = PI[p] + 1; j <= PI[xdivy2]; j++){
            int q = Prime[j];
            V2 += PI[x / (p * q)];
        }
    }

#endif

    printf("V2 = %lld\n", V2);

    return V2;
}

int main(int argc, char* argv[])
{
    clock_t start = clock();

 if (argc > 1)
  MAXN = atoll(argv[1]); //mingw

    init_x( );

    sieve( );

    init_PI( );

    init_minFactor( );
    init_phiTable( );

    int64 pix = PI[y] - 1;
    pix += cal_S3( ); //mul thread

    pix -= cal_P2xa( );
    pix += cal_S0( );


    if (y != x13){
        pix += cal_S1( );
        pix += cal_U( );
    }

    pix += cal_V2( );
    pix += cal_V1( );

#if 0
    printf("phi(%u, 209) = %d, time = %ld ms\n", x, phi(x, 209), clock() - start);
    delete phiTable;
    return 0;
#endif

    puts("\nPi(x) = phi(x, a) + a - 1 - phi2(x,a):");

    printf("pi(%lld) = %lld, time use %ld ms\n", x, pix, clock() - start);

    freememory(1);
    return 0;
}

//benchmark, Windows Xp SP2, 1G, Mingw G++ 3.4.5
// pi(  2147483647) = 105097565,  time use  108 ms (machine AMD    3600+  2.0G)
// pi(100000000000) = 4118054813, time use 2171 ms (machine intel PD 940  3.2G)