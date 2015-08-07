#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<memory.h>
#include<algorithm>
using namespace std;
const int MAXN = 50000 + 5;

int N;
int dp[MAXN];
int phi[MAXN];

//筛法求 1 - n 内所有数的欧拉函数的值
void phiTable(int n)
{
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;

	for(int i = 2; i < n; ++ i)
		if(phi[i] == 0)
			for(int j = i; j < n; j += i)
			{
				if(phi[j] == 0)
					phi[j] = j;

				phi[j] = phi[j] / i * (i - 1);
			}
}

void init()
{
	phiTable(MAXN);
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;

	for(int i = 2; i < MAXN; ++ i)
		dp[i] += dp[i - 1] + (phi[i] << 1);
}

int main()
{
	init();

	while(scanf("%d", &N) != EOF && N)
		printf("%d\n", dp[N]);

	return 0;
}