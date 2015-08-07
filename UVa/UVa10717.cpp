#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<cstdio>
#include <iostream>
using namespace std;
const int MAXN = 50 + 5;
const int INF = 0x7fffffff;

int n, t, ex;
set<int> ans;
int thick[MAXN];
set<int>::const_iterator itor;

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y)
{
	if(x < y)
		return lcm(y, x);

	return x / gcd(x, y) * y;
}

int main()
{
	while(scanf("%d%d", &n, &t) == 2 && (n || t))
	{
		for(int i = 0; i < n; ++ i)
			scanf("%d", &thick[i]);

		ans.clear();

		for(int i = 0; i < n; ++i)
			for(int j = i + 1; j < n; ++ j)
			{
				int lcmij = lcm(thick[i], thick[j]);

				for(int p = j + 1; p < n; ++ p)
				{
					int lcmijp = lcm(lcmij, thick[p]);

					for(int q = p + 1; q < n; ++ q)
						ans.insert(lcm(lcmijp, thick[q]));
				}
			}

		for(int k = 0; k < t; ++ k)
		{
			scanf("%d", &ex);
			int up = INF;
			int down = 0;

			for(set<int>::const_iterator itor = ans.begin(); itor != ans.end(); ++ itor)
			{
				if (up > (ex % (*itor) ? (ex / (*itor) * (*itor) + (*itor)) : ex))
					up = (ex % (*itor) ? (ex / (*itor) * (*itor) + (*itor)) : ex);

				if (down < ex / (*itor) * (*itor))
					down = ex / (*itor) * (*itor);
			}

			printf("%d %d\n", down, up);
		}
	}

	return 0;
}