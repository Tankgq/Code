#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
using namespace std;

int ja, jb;
int a, b, n;

inline void FillA()
{
	ja = a;
	puts("fill A");
}

inline void PourAtoB()
{
	if(ja == 0)
		FillA();

	jb += ja;
	ja = 0;

	if(jb > b)
	{
		ja = jb - b;
		jb = b;
	}

	puts("pour A B");
}

inline void EmptyB()
{
	jb = 0;
	puts("empty B");
}

int main()
{
	while(scanf("%d%d%d", &a, &b, &n) == 3)
	{
		for(ja = jb = 0; jb != n; PourAtoB())
			if(jb == b)
				EmptyB();

		puts("success");
	}

	return 0;
}