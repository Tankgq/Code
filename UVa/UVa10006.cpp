#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 65000 + 5;

int n;
int vis[MAXN];

//素数筛筛素数，vis[质数] = false;
void sieve(int n)
{
	int m = (int)sqrt(n + 0.5);
	memset(vis, false, sizeof(vis));

	for(int i = 2; i <= m; ++i)
		if(vis[i] == false)
			for(int j = i * i; j <= n; j += i)
				vis[j] = true;
}

int QuickPow(int p, int k, int mod)
{
	int res = 1;

	while(k)
	{
		if(k & 1)
			res = ((LL)res * (LL)p) % mod;

		p = ((LL)p * (LL)p) % mod;
		k >>= 1;
	}

	return res;
}

bool FermatTest(int x)
{
	for(int i = 2; i < n; ++ i)
		if(QuickPow(i, n, n) != i)
			return false;

	return true;
}

int main()
{
	sieve(MAXN);

	while(scanf("%d", &n) != EOF && n)
		if(vis[n] && FermatTest(n))
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);

	return 0;
}