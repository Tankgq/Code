#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
const int MAXN = 1000 + 5;

int N, I;
double pro;

int main()
{
	int S;
	scanf("%d", &S);

	while(S-- && ~scanf("%d%lf%d", &N, &pro, &I))
		printf("%.4lf\n", pro == 0.0 ? pro : pro * pow(1 - pro, I - 1) / (1 - pow(1 - pro, N)));

	return 0;
}