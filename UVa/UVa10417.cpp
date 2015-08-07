#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
const int MAXN = 12 + 5;

int n;
int gift[5];
double p[MAXN][5];

int main()
{
    int T;
    scanf("%d", &T);

    while(T --)
    {
        scanf("%d", &n);

        for(int i = 0; i < 5; ++ i)
            scanf("%d", gift + i);

        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < 5; ++ i)
                scanf("%lf", &p[i][j]);
    }

    return 0;
}