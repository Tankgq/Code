#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;
const int MAXN = 10000 + 5;

char str[100];
int x, y, dist, ans;
vector< pair<int, int> > village[MAXN];

int max(int a, int b)
{
	return a > b ? a : b;
}

int dfs(int cur, int prev)
{
	int tans, tmax = 0;

	for(int i = 0; i < village[cur].size(); ++ i)
		if(village[cur][i].first != prev)
		{
			tans = dfs(village[cur][i].first, cur) + village[cur][i].second;
			ans = max(ans, tans + tmax);
			tmax = max(tmax, tans);
		}

	return tmax;
}

int main()
{
	//freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	bool flag = true;

	while(flag)
	{
		for(int i = 0; i < MAXN; ++ i)
			village[i].clear();

		if(gets(str) == NULL)
			break;

		if(str[0] != '\0')
		{
			sscanf(str, "%d%d%d", &x, &y, &dist);
			village[x].push_back(make_pair(y, dist));
			village[y].push_back(make_pair(x, dist));
		}
		else
		{
			puts("0");
			continue;
		}

		while(true)
		{
			if(gets(str) == NULL)
			{
				flag = false;
				break;
			}

			if(str[0] == '\0')
				break;

			sscanf(str, "%d%d%d", &x, &y, &dist);
			village[x].push_back(make_pair(y, dist));
			village[y].push_back(make_pair(x, dist));
		}

		ans = 0;
		dfs(1, 0);
		printf("%d\n", ans);
	}

	return 0;
}
