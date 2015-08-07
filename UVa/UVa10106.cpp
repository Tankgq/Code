#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
typedef long long LL;
const int MAXN = 50000 + 5;
const int D_MOD = 1000000000;
const int MOD = 9;

char a[MAXN], b[MAXN];

class BigNumber
{
public:
	int intLen;
	LL integer[MAXN / MOD];

	BigNumber()
	{
		this->intLen = 1;
		memset(this->integer, 0, sizeof(this->integer));
	}
};

void ChangeToArray(char *str, BigNumber &bignumber)
{
	//初始化
	memset(bignumber.integer, 0, sizeof(bignumber.integer));
	int iLen = (int)strlen(str);
	//inte指向字符串的结尾
	char *itg = str + iLen;
	bignumber.intLen = (iLen + MOD - 1) / MOD;

	//从字符串后面开始每次取 MOD 位
	//eg. str = "123456789", MOD = 4, 存储为 6789, 2345, 1
	for(int i = 0; i < bignumber.intLen - 1 && (itg -= MOD); ++i)
		sscanf(itg, "%9d", &bignumber.integer[i]);

	itg[0] = '\0';
	itg = str;
	sscanf(itg, "%d", &bignumber.integer[bignumber.intLen - 1]);

	//去除前导零，注意不能去掉大整数等于0的情况
	for(int i = bignumber.intLen - 1; i > 0; --i)
	{
		if(bignumber.integer[i] == 0)
			--bignumber.intLen;
		else
			break;
	}
}

void Plus(BigNumber &A, BigNumber &B, BigNumber &C)
{
	LL temp = 0;
	C.intLen = A.intLen > B.intLen ? A.intLen : B.intLen;

	for(int i = 0; i < C.intLen; ++i)
	{
		LL t = A.integer[i] + B.integer[i] + temp;
		C.integer[i] = t % D_MOD;
		temp = t / D_MOD;
	}

	if(temp != 0)
		C.integer[C.intLen++] = temp;
}

void Multiply(BigNumber &A, BigNumber &B, BigNumber &C)
{
	//保证A 的长度比 B 的长度来的长
	if(A.intLen < B.intLen)
	{
		Multiply(B, A, C);
		return;
	}

	LL temp;
	C.intLen = A.intLen + B.intLen;

	for(int i = 0; i < B.intLen; ++i)
	{
		temp = 0;

		for(int j = 0; j < A.intLen; ++j)
		{
			LL t = C.integer[i + j] + A.integer[j] * B.integer[i] + temp;
			C.integer[i + j] = t % D_MOD;
			temp = t / D_MOD;
		}

		if(temp != 0)
			C.integer[A.intLen + i] += temp;
	}

	for(int i = C.intLen - 1; i >= 0; --i)
		if(C.integer[i] == 0)
			--C.intLen;
		else
			break;
}

void Show(BigNumber &bignumber)
{
	printf("%d", bignumber.integer[bignumber.intLen - 1]);

	for(int i = bignumber.intLen - 2; i >= 0; --i)
		printf("%09d", bignumber.integer[i]);

	printf("\n");
}

int main()
{
	while(scanf("%s %s", a, b) != EOF)
	{
		BigNumber A, B;
		ChangeToArray(a, A);
		ChangeToArray(b, B);
		BigNumber C;
		Multiply(A, B, C);
		Show(C);
	}

	return 0;
}