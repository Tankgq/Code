#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
const int MAXN = 16;

int gap;
int p[MAXN][MAXN];
double dp[4][MAXN];
char name[MAXN][MAXN];

int main()
{
	for(int i = 0; i < MAXN; ++ i)
		gets(name[i]);

	for(int i = 0; i < MAXN; ++ i)
		for(int j = 0; j < MAXN; ++ j)
			scanf("%d", &p[i][j]);

	for(int i = 0; i < MAXN; ++ i)
		dp[0][i] = (i & 1 ? p[i][i ^ 1] : p[i][i | 1]) / 100.0;

	for(int i = 1; i < 4; ++ i)
	{
		gap = 1 << i;

		for(int j = 0; j < MAXN; ++ j)
		{
			double tmp = 0;
			int fir = j - j % gap + ((j / gap) & 1 ? -gap : gap);

			for(int g = 0; g < gap; ++ g)
				tmp += dp[i - 1][fir + g] * p[j][fir + g] / 100.0;

			dp[i][j] = tmp * dp[i - 1][j];
		}
	}

	for(int i = 0; i < MAXN; ++ i)
		printf("%-10s p=%.2lf%%\n", name[i], dp[3][i] * 100);

	return 0;
}
