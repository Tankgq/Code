#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
const int MAXN = 1000 + 5;
const int INF = 0x7fffffff;

char op;
double aa, bb;
char a[MAXN], b[MAXN];

int main()
{
	while(scanf("%s %c %s", a, &op, b) == 3)
	{
		printf("%s %c %s\n", a, op, b);
		aa = atof(a);
		bb = atof(b);

		if(aa > INF)
			puts("first number too big");

		if(bb > INF)
			puts("second number too big");

		if((op == '+' && aa + bb > INF) || (op == '*' && aa * bb > INF))
			puts("result too big");
	}
	
	return 0;
}