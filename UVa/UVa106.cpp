#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 1000 + 5;

int cnt;
int N, p;
int a, b, c;
int vis[MAXN * MAXN];

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        cnt = p = 0;
        memset(vis, 0, sizeof(vis));

        for(int n = 1; n * n <= N; ++ n)
            for(int m = n + 1; (c = n * n + m * m) && c <= N; ++ m)

                //m 和 n 同奇偶，那么a，b，c都会是偶数
                if((m & 1) + (n & 1) == 1 && gcd(m, n) == 1)
                {
                    ++ cnt;
                    b = (m * n) << 1;
                    a = m * m - n * n;

                    for(int k = 1; c * k <= N; ++k)
                        vis[k * a] = vis[k * b] = vis[k * c] = 1;
                }

        for(int i = 1; i <= N; ++ i)
            if(vis[i] == 0)
                ++ p;

        printf("%d %d\n", cnt, p);
    }

    return 0;
}