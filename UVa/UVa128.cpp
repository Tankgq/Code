#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;
const int MOD = 34943;
const int MAXN = 1024 + 5;

unsigned ans;
char info[MAXN];

int main()
{
	while(gets(info) != NULL && (info[0] != '#' || info[1] != '\0'))
	{
		if(info[0] == '\0')
		{
			puts("00 00");
			continue;
		}

		ans = 0;

		for(int i = 0; info[i] != '\0'; ++ i)
			ans = ((ans << 8) + info[i]) % MOD;

		ans = (ans << 16) % MOD;
		ans = MOD - ans;
		printf("%02X %02X\n", (ans >> 8), ((ans << 24) >> 24));
	}

	return 0;
}