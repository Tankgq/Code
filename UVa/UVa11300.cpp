#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1e6 + 5;

int n, x1;
LL ans, ave;
int coins[MAXN], t[MAXN];

int abs(int x)
{
	int sgn = x >> 31;
	return (x ^ sgn) - sgn;
}

int main()
{
	while(~scanf("%d", & n))
	{
		ans = ave = 0;

		for(int i = 0; i < n; ++ i)
		{
			scanf("%d", &coins[i]);
			ave += coins[i];
		}

		ave /= n;

		for(int i = 1; i < n; ++ i)
			t[i] = t[i - 1] + coins[i] - ave;

		sort(t, t + n);
		x1 = t[n / 2];

		for(int i = 0; i < n; ++ i)
			ans += abs(x1 - t[i]);

		printf("%lld\n", ans);
	}

	return 0;
}
