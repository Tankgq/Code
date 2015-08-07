#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const int MAXN = 64 + 5;

int n, flag;
int ans[MAXN];

int main()
{
	int tCase;

	while(scanf("%d", &tCase) != EOF)
		for(int T = 1; T <= tCase; ++ T)
		{
			flag = 1;
			scanf("%d", &n);
			memset(ans, 0, sizeof(ans));

			if(n < 0)
			{
				flag = 0;
				n = ~n + 1;
			}

			//转化
			for(int i = 0; i < 31; ++ i)
				if(n & (1 << i))
				{
					++ans[i];

					if((i & 1) == flag)
						++ans[i + 1];
				}

			//进位
			for(int i = 0; i < MAXN - 1; ++ i)
			{
				//抵消
				if(ans[i] >= ((ans[i + 1] >> 1) << 1))
				{
					ans[i] -= ((ans[i + 1] >> 1) << 1);
					ans[i + 1] -= (ans[i + 1] >> 1);
				}

				while(ans[i] > 1)
				{
					++ans[i + 1];
					++ans[i + 2];
					ans[i] -= 2;
				}
			}

			printf("Case #%d: ", T);

			for(int i = MAXN - 1; i > 0; -- i)
				if(ans[i] != 0)
				{
					for(int j = i; j > 0; --j)
						putchar(ans[j] + '0');

					break;
				}

			putchar(ans[0] + '0');
			putchar('\n');
		}

	return 0;
}
