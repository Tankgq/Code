#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;

double ans;
int p, q, r, s;

int main()
{
	while(scanf("%d%d%d%d", &p, &q, &r, &s) == 4)
	{
		ans = 1;
		q = min(q, p - q);
		s = min(s, r - s);
		int n = min(q, s);

		for(int i = 1; i <= n; ++ i)
			ans = ans / (r - s + i) * (p - q + i);

		if(q > s)
			for(int i = s + 1; i <= q; ++ i)
				ans = ans / i * (p - q + i);
		else
			for(int i = q + 1; i <= s; ++ i)
				ans = ans / (r - s + i) * i;

		printf("%.5lf\n", ans);
	}

	return 0;
}