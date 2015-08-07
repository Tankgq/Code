//#define FREOPEN_IN
//#define FREOPEN_OUT
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 300 + 5;
const int INF = 0x7fffffff;

char tmp[MAXN];
char str[MAXN];
char after[MAXN][MAXN];
char before[MAXN][MAXN];

int main()
{
	char *p;
	int n;

	while(scanf("%d%*c", &n) == 1 && n)
	{
		for(int i = 0; i < n; ++i)
			gets(before[i]), gets(after[i]);

		gets(str);

		for(int i = 0; i < n; ++i)
			while(true)
			{
				p = strstr(str, before[i]);

				if(p == NULL)
					break;

				strcpy(tmp, p + strlen(before[i]));
				strcpy(p, after[i]);
				strcat(p, tmp);
			}

		puts(str);
	}

	return 0;
}