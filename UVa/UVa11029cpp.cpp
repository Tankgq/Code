#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>

int n, k;

int ProDigitPow(int x, int k, int len)
{
	//return (int)pow(10, len - 1 + fmod(k * log10(n * 1.0), 1.0));
	return (int)pow(10, len + k * log10(n) - (int)(k * log10(n)) - 1);
}

int QAuickPow(int x, int k, int mod)
{
	x %= mod;
	int res = 1;

	while(k)
	{
		if(k & 1)
			res = (res * x) % mod;

		k >>= 1;
		x = (x * x) % mod;
	}

	return res;
}

int main()
{
	int T;
	scanf("%d", &T);

	while(T--)
	{
		scanf("%d%d", &n, &k);
		printf("%d...%03d\n", ProDigitPow(n, k, 3), QAuickPow(n, k, 1000));
	}

	return 0;
}