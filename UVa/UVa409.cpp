#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctype.h>
#include<cstring>
const int MAXN = 70 + 5;

int num[MAXN];
char temp[MAXN];
char excuses[MAXN][MAXN];
char keywords[MAXN][MAXN];

int main()
{
	int k, e;
	int tCase = 0;

	while(scanf("%d%d%*c", &k, &e) == 2)
	{
		int max = -1;
		memset(num, 0, sizeof(num));

		for(int i = 0; i < k; ++i)
		{
			gets(keywords[i]);
			strcat(keywords[i], " ");
			//bee
			//bee ch
			//beech
			//bee.
		}

		for(int i = 0; i < e; ++ i)
		{
			gets(excuses[i]);
			int p;
			int len = strlen(excuses[i]);

			for(p = 0; p < len; ++p)
			{
				if(isalpha(excuses[i][p]))
					temp[p] = tolower(excuses[i][p]);
				else
					temp[p] = ' ';
			}

			temp[p] = '\0';

			for(int j = 0; j < k; ++ j)
				if(strstr(temp, keywords[j]) != NULL)
					++num[i];

			if(num[i] > max)
				max = num[i];
		}

		printf("Excuse Set #%d\n", ++tCase);

		for(int i = 0; i < e; ++ i)
			if(num[i] == max)
				puts(excuses[i]);

		putchar('\n');
	}

	return 0;
}