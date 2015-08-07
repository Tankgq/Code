#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
const int MAXN = 13;

int ans;
int n, k;
int fact[MAXN];

int main()
{
	fact[0] = 1;

	for(int i = 1; i < MAXN; ++ i)
		fact[i] = i * fact[i - 1];

	while(scanf("%d%d", &n, &k) == 2)
	{
		int tmp;
		ans = fact[n];

		for(int i = 0; i < k; ++i)
		{
			scanf("%d", &tmp);
			ans /= fact[tmp];
		}

		printf("%d\n", ans);
	}

	return 0;
}