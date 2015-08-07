#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
const int MAXN = 20 + 5;

int n, r;
double total;
double p[MAXN];

double dfs(int cur, int len, int k = n)
{
    if(cur == n)
        return len ? 0.0 : 1.0;

    if(cur == k)
        return p[cur] * dfs(cur + 1, len - 1, k);

    return (1 - p[cur]) * dfs(cur + 1, len, k) + (len ? p[cur] * dfs(cur + 1, len - 1, k) : 0.0);
}

int main()
{
    int Tcase = 0;

    while(~scanf("%d%d", &n, &r) && (n || r))
    {
        for(int i = 0; i < n; ++ i)
            scanf("%lf", p + i);

        total = dfs(0, r);
        printf("Case %d:\n", ++ Tcase);

        for(int i = 0; i < n; ++ i)
            printf("%.6lf\n",  dfs(0, r, i) / total);
    }

    return 0;
}