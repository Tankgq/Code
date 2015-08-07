#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
const int MAXN = 50000;

int n;
double dp[MAXN];

int main()
{
	int T;
	dp[0] = 1.0;
    scanf("%d", &T);

    for(int i = 1; i < MAXN; ++ i)
        dp[i] = dp[i - 1] * ((i << 1) - 1) / (i << 1);

    while(T-- && ~scanf("%d", &n))
        printf("%.4lf\n", 1.0 - dp[(n >> 1) - 1]);

    return 0;
}