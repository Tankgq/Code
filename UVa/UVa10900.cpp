#define _CRT_SECURE_NO_WARNINGS
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 5;

int n;
double t, ep, ans;

int main()
{
    while(~scanf("%d%lf", &n, &t))
    {
        if(n == 0 && t == 0.0)
            break;

        if(t < 0.5)
        {
            ans = 1 << n;

            for(int i = n - 1; i >= 0; -- i)
            {
                ep = (1 << i) / ans;

                if(t < ep)
                    ans = ((ep - t) * (1 << i) + 0.5 * (1 - ep * ep) * ans) / (1 - t);
                else
                    ans = 0.5 * (1 + t) * ans;
            }
        }
        else
            ans = (1 << n) * pow(0.5 * (t + 1), n);

        printf("%.3lf\n", ans);
    }

    return 0;
}
