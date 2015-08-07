#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
using namespace std;

double car, cow, show;

int main()
{
    while(~scanf("%lf%lf%lf", &cow, &car, &show))
        printf("%.5lf\n", car * (cow + car - 1) / (cow + car) / (cow + car - show - 1));

    return 0;
}