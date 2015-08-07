#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN = 50000;
const int MAXP = 64 + 5;


int N, p, x;
int numPrime;
long long ans;
int vis[MAXN];
int prime[MAXN / 6];

//����ɸɸ������vis[����] = false;
void sieve(int n)
{
	int m = (int)sqrt(n + 0.5);
	memset(vis, false, sizeof(vis));

	for(int i = 2; i <= m; ++ i)
		if(vis[i] == false)
			for(int j = i * i; j <= n; j += i)
				vis[j] = true;
}

void init()
{
	sieve(MAXN);
	numPrime = -1;

	for(int i = 2; i < MAXN; ++ i)
		if(vis[i] == false)
			prime[++numPrime] = i;
}

int main()
{
	init();
	int tCase = 0;

	while(scanf("%d", &N) && N)
	{
		int n = N;
		ans = x = 0;

		for(int i = 0; n > 1 && i <= numPrime; ++ i)
			if(n % prime[i] == 0)
			{
				n /= prime[i];
				p = prime[i];

				while(n % prime[i] == 0)
				{
					n /= prime[i];
					p *= prime[i];
				}

				//������������++
				++x;
				ans += p;
			}

		//ֻ��һ���������� N = 1
		if(x == 1 || N == 1)
			++ans;

		//����49999������������ N = 1��ע��2147483647������
		if(N == n)
			ans = N + 1LL;

		printf("Case %d: %lld\n", ++ tCase, ans);
	}

	return 0;
}