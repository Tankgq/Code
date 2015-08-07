#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
const int MAXN = 1000000;
typedef unsigned int uint;

uint n;
int num[MAXN], len;
double ans[MAXN], tmp;

int main()
{
    ans[1] = 0.5;

    for(int i = 2; i < MAXN; ++ i)
        ans[i] = ans[i - 1] * ((i + 2.0) / (i + 1) - 1.0 / i);

    num[1] = 0, tmp = 5;

    for(int i = 2; i < MAXN; ++ i)
    {
        len = 0;
        num[i] = num[i - 1];
        tmp *= (1.0 / i - 1.0 / (i + 1));

        while(((int) tmp) % 10 == 0)
        {
            ++ num[i];
            tmp *= 10;
			//tmp = fmod(tmp * 10, 10.0);
        }
    }

    while(~scanf("%d", &n))
        printf("%.6lf %d\n", 1 - ans[n], num[n]);

    return 0;
}