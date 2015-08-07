/*
#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
const int MAXN = 22000 + 5;
const int MAXSIZE = MAXN << 4;

int cnt, n;
int prime[MAXN];
bool vis[MAXSIZE];
long long fibs[MAXSIZE];

void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis, false, sizeof(vis));

    for(int i = 2; i <= m; ++ i)
        if(vis[i] == false)
            for(int j = i * i; j <= n; j += i)
                vis[j] = true;
}

void prepare()
{
    cnt = 2;
    sieve(MAXSIZE);
    prime[1] = 3, prime[2] = 4;

    for(int i = 5; i < MAXSIZE && cnt < MAXN; ++ i)
        if(vis[i] == false)
            prime[++ cnt] = i;

    fibs[0] = 0, fibs[1] = 1;

    for(int i = 2; i < MAXSIZE; ++ i)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];

        if(fibs[i] > 1000000000000000000LL)
        {
            fibs[i] /= 10;
            fibs[i - 1] /= 10;
        }
    }
}

int solve(long long x)
{
    while(x > 1000000000)
        x /= 10;

    return (int)x;
}

int main()
{
    prepare();

    while(~scanf("%d", &n))
        printf("%d\n", solve(fibs[prime[n]]));

    return 0;
}*/

/*
#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
const int MAXN = 22000 + 5;
const int MAXSIZE = MAXN << 4;

int cnt, n;
int prime[MAXN];
bool vis[MAXSIZE];
double fibs[MAXSIZE];

void sieve(int n)
{
    int m = (int)sqrt(n + 0.5);
    memset(vis, false, sizeof(vis));

    for(int i = 2; i <= m; ++ i)
        if(vis[i] == false)
            for(int j = i * i; j <= n; j += i)
                vis[j] = true;
}

void prepare()
{
    cnt = 2;
    sieve(MAXSIZE);
    prime[1] = 3, prime[2] = 4;

    for(int i = 5; i < MAXSIZE && cnt < MAXN; ++ i)
        if(vis[i] == false)
            prime[++ cnt] = i;

    fibs[0] = 0, fibs[1] = 1;

    for(int i = 2; i < MAXSIZE; ++ i)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];

        if(fibs[i] > 1e18)
        {
            fibs[i] /= 10;
            fibs[i - 1] /= 10;
        }
    }
}

int prodigit(double x, int len = 9)
{
    if(x >= 1e8)
        return (int)pow(10, log10(x) - (int)log10(x) + len - 1);

    return (int)x;
}

int main()
{
    prepare();

    while(~scanf("%d", &n))
        printf("%d\n", prodigit(fibs[prime[n]]));

    return 0;
}*/