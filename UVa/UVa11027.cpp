#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN = 30 + 5;

LL fact[16];
char OddChar;
int n, len, num[26];
char str[MAXN], ans[MAXN];

//计算有多少种
LL Permutation(int len)
{
	LL res = fact[len];

	for(int i = 0; i < 26; ++i)
		res /= fact[num[i]];

	return res;
}

LL MaxPalindromic()
{
	memset(num, 0, sizeof(num));

	for(int i = 0; str[i] != '\0'; ++i)
		++num[str[i] - 'a'];

	int OddNum = 0;

	for(int i = 0; i < 26; ++ i)
	{
		if(num[i] & 1)
		{
			++OddNum;
			OddChar = i + 'a';
		}

		num[i] >>= 1;
	}

	if(OddNum > 1)
		return 0LL;

	if(OddNum == 0)
		OddChar = '#';

	len = strlen(str) >> 1;
	return Permutation(len);
}

void solve(LL x, int n)
{
	for(int i = 0; i < len; ++ i)
		for(int j = 0; j < 26; ++ j)
			if(num[j])
			{
				--num[j];
				LL tmp = Permutation(n - 1 - i);

				if(tmp < x)
				{
					++num[j];
					x -= tmp;
					continue;
				}

				ans[i] = j + 'a';
				break;
			}
}

/*
void dfs(int cur, int n, LL x)
{
	if(n == 0)
		return;

	for(int i = 0; i < 26; ++ i)
		if(num[i])
		{
			--num[i];
			LL tmp = Permutation(n - 1);

			if(tmp < x)
			{
				++num[i];
				x -= tmp;
				continue;
			}

			ans[cur] = i + 'a';
			dfs(cur + 1, n - 1, x);
		}
}*/

int main()
{
	int T;
	scanf("%d", &T);
	fact[0] = 1;

	for(int i = 1; i < 16; ++ i)
		fact[i] = fact[i - 1] * i;

	for(int tCase = 1; tCase <= T; ++ tCase)
	{
		scanf("%s%d", str, &n);
		printf("Case %d: ", tCase);
		LL MaxNumber = MaxPalindromic();

		if(MaxNumber < n)
			puts("XXX");
		else
		{
			//dfs(0, len, n);
			solve(n, len);

			for(int i = 0; i < len; ++ i)
				putchar(ans[i]);

			if(OddChar != '#')
				putchar(OddChar);

			for(int i = len - 1; i >= 0; -- i)
				putchar(ans[i]);

			putchar('\n');
		}
	}

	return 0;
}