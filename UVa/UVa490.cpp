#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
const int MAXN = 100 + 5;

int len[ MAXN ];
char str[ MAXN ][ MAXN ];

int main()
{
	int n = 0;
	int maxLen = 0x80000001;
	while(gets(str[n]) != NULL)
	{
		len[n] = strlen(str[n]);
		if(len[n] > maxLen)
			maxLen = len[n];
		++ n;
	}
	for(int j = 0; j < maxLen; ++ j)
	{
		for(int i = n - 1; i >= 0; -- i)
			if(j < len[i])
				printf("%c", str[i][j]);
			else
				putchar(' ');
		puts("");
	}
	//system("pause");
	return 0;
}