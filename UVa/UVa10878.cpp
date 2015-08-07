#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

int main()
{
	char ch;
	int i = 1, ans;

	while((ch = getchar()) != EOF)
	{
		if(ch == '\n')
		{
			if(!i)
				putchar(ans);

			i = 128;
			ans = 0;
		}
		else if(ch == 'o')
		{
			ans += i;
			i >>= 1;
		}
		else if(ch == ' ')
			i >>= 1;
	}

	return 0;
}
