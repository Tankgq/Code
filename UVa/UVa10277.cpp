#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
const unsigned int MAXN = 50000;

unsigned int d;
unsigned int p, q, x;

unsigned int gcd(unsigned int x, unsigned int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int solve()
{
    if(p == q)
    {
        puts("2 0");
        return 1;
    }

    if(p == 0)
    {
        puts("0 2");
        return 1;
    }

    d = gcd(p, q);
    p /= d, q /= d;

    for(unsigned int t = 2; t <= MAXN; ++ t)
    {
        if((t * (t - 1)) % q == 0)
        {
            long long tmp = (long long)(t * (t - 1) / q) * (long long) p;

            if(tmp > 2499950000LL)
                continue;

            x = (unsigned int)sqrt((unsigned int)tmp + 0.5);

            if(x * (x + 1) == tmp)
            {
                printf("%d %d\n", x + 1, t - x - 1);
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    while(~scanf("%d%d", &p, &q) && (p || q))
        if(solve() == 0)
            puts("impossible");

    return 0;
}