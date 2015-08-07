#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN = 24 + 5;

int n, x;
int two, three;
LL dp[MAXN][MAXN * 6];
LL numerator, denominator;

int main()
{
	memset(dp, 0, sizeof(dp));

	for(int k = 1; k <= 6; ++ k)
		dp[1][k] = 1LL;

	for(int i = 2; i <= 24; ++ i)
		for(int j = i; j <= 6 * i; ++ j)
			for(int k = 1; k <= 6; ++ k)
				dp[i][j] += dp[i - 1][j - k];

	while(~scanf("%d%d", &n, &x) && (n || x))
	{
		if(x > n * 6)
		{
			puts("0");
			continue;
		}

		if(x <= n)
		{
			puts("1");
			continue;
		}

		two = three = n;
		numerator = 0LL;

		for(int k = x; k <= 6 * n; ++ k)
			numerator += dp[n][k];

		while(two && !(numerator & 1))
		{
			-- two;
			numerator >>= 1;
		}

		while(three && !(numerator % 3))
		{
			-- three;
			numerator /= 3;
		}

		denominator = (1LL << two);

		for(int i = 0; i < three; ++ i)
			denominator *= 3;

		printf("%lld/%lld\n", numerator, denominator);
	}

	return 0;
}