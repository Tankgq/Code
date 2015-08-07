#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while(t --)
	{
		int A, F;
		scanf("%d%d", &A, &F);
		for(int k = 0; k < F; ++ k)
		{
			for(int i = 0; i < A; ++ i)
			{
				for(int j = 0; j <= i; ++ j)
					putchar('1' + i);
				putchar('\n');
			}
			for(int i = A - 1; i > 0; -- i)
			{
				for(int j = 0; j < i; ++ j)
					putchar('0' + i);
				putchar('\n');
			}
			if(k != F - 1)
				putchar('\n');
		}
		if(t)
			putchar('\n');
	}
	return 0;
}
