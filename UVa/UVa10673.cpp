#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

int x, k, p, q;

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &x, &k);
		printf("%d %d\n", k - x % k, x % k);
	}

	return 0;
}