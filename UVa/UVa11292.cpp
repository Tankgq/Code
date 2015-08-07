#include<cstdio>
#include<cstring>
const int MAXN = 2e4 + 5;
#define min(a, b) (a) < (b) ? (a) : (b)

int N, M, t, ans, mi;
int dra[MAXN], kni[MAXN];

int calc()
{
	ans = 0;

	for(int i = 0, j = 0; i < MAXN; ++ i)
		while(dra[i])
		{
			if(i > j)
				j = i;

			while(j < MAXN && !kni[j])
				++ j;

			if(j == MAXN)
				return 0;

			mi = min(dra[i], kni[j]);
			dra[i] -= mi, kni[j] -= mi;
			ans += mi * j;
		}

	return 1;
}

int main()
{
	while(~scanf("%d%d", &N, &M) && (N || M))
	{
		memset(dra, 0, sizeof(dra));
		memset(kni, 0, sizeof(kni));

		for(int i = 0; i < N; ++ i)
		{
			scanf("%d", &t);
			++ dra[t];
		}

		for(int i = 0; i < M; ++ i)
		{
			scanf("%d", &t);
			++ kni[t];
		}

		if(calc())
			printf("%d\n", ans);
		else
			puts("Loowater is doomed!");
	}

	return 0;
}