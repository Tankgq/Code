#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
typedef long long LL;
const int MOD = 10;
const int MAXN = 100 + 5;
const LL D_MOD = 10000000000;

char a[MAXN];

class BigNumber
{
public:
	int len;
	LL number[MAXN / MOD];

	BigNumber()
	{
		this->len = 1;
		memset(number, 0, sizeof(number));
	}
};

void ChangeToArray(char *str, BigNumber &bignumber)
{
	int i;
	int len = (int)strlen(str);
	bignumber.len = (len + MOD - 1) / MOD;

	for(i = 0, str += len; i < bignumber.len - 1 && (str -= MOD); ++i)
		sscanf(str, "%10lld", &bignumber.number[i]);

	if(len > MOD)
		str[0] = '\0';

	str -= (len % MOD) ? (len % MOD) : MOD;
	sscanf(str, "%lld", &bignumber.number[bignumber.len - 1]);

	for(i = bignumber.len - 1; i > 0; --i)
	{
		if(bignumber.number[i] == 0)
			--bignumber.len;
		else
			break;
	}
}

void Plus(BigNumber &A, BigNumber &B, BigNumber &C)
{
	LL temp = 0;
	C.len = A.len > B.len ? A.len : B.len;

	for(int i = 0; i < C.len; ++i)
	{
		LL t = A.number[i] + B.number[i] + temp;
		C.number[i] = t % D_MOD;
		temp = t / D_MOD;
	}

	if(temp != 0)
		C.number[C.len++] = temp;
}

void Show(BigNumber &bignumber)
{
	printf("%lld", bignumber.number[bignumber.len - 1]);

	for(int i = bignumber.len - 2; i >= 0; --i)
		printf("%010lld", bignumber.number[i]);

	putchar('\n');
}

int main()
{
	BigNumber res;
	BigNumber temp;

	while(gets(a) != NULL && a[0] != '0')
	{
		ChangeToArray(a, temp);
		Plus(res, temp, res);
	}

	Show(res);
	return 0;
}