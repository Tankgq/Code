#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<ctype.h>
const int MAXN = 1000 + 5;

char str[MAXN];

void cal(char *p, char unit, double &num)
{
	if(p == NULL)
		return;

	p += 2;

	while(isdigit(*p))
	{
		num = num * 10 + (*p - '0');
		++p;
	}

	if(*p == '.')
	{
		++p;
		double d = 10;

		while(isdigit(*p))
		{
			num += (*p - '0') / d;
			d *= 10;
			++p;
		}
	}

	if(*p == unit)
		return;
	else if(*p == 'm')
		num *= 1e-3;
	//num *= 0.001;
	else if(*p == 'k')
		num *= 1e3;
	//num *= 1000.0;
	else if(*p == 'M')
		num *= 1e6;
		//num *= 1000000.0;
}

int main()
{
	int tCase;
	scanf("%d%*c", &tCase);

	for(int tcase = 1; tcase <= tCase; ++ tcase)
	{
		gets(str);
		double u = 0, i = 0, p = 0;
		char *pu = strstr(str, "U=");
		char *pi = strstr(str, "I=");
		char *pp = strstr(str, "P=");
		cal(pi, 'A', i);
		cal(pu, 'V', u);
		cal(pp, 'W', p);
		printf("Problem #%d\n", tcase);

		if(pu == NULL)
			printf("U=%.2lfV\n", p / i);
		else if(pi == NULL)
			printf("I=%.2lfA\n", p / u);
		else
			printf("P=%.2lfW\n", i * u);

		putchar('\n');
	}

	return 0;
}