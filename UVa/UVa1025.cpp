#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<bitset>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include<complex>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAXN = 2e2 + 5;
const int INF = 0x18181818;
const double PI = acos(-1.0);
typedef unsigned long long uLL;

int N, T, M1, M2, tot, st;
int t[55], stf[55][205], stl[55][205], dp[55][205];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
#endif
    int tCase = 0;

    while(~scanf("%d", &N) && N)
    {
        scanf("%d", &T);
        tot = t[0] = t[N] = 0;
        memset(stf, 0, sizeof(stf));
        memset(stl, 0, sizeof(stl));

        for(int i = 1; i < N; tot += t[i], ++ i)
            scanf("%d", &t[i]);

        scanf("%d", &M1);

        for(int i = 0; i < M1; ++ i)
        {
            scanf("%d", &st);

            for(int j = 0, ti = st; j < N && ti + t[j] <= T; ti += t[j], ++ j)
                stf[j + 1][ti + t[j]] = 1;
        }

        scanf("%d", &M2);

        for(int i = 0; i < M2; ++ i)
        {
            scanf("%d", &st);

            for(int j = N, ti = st; j > 0 && ti + t[j] <= T; ti += t[j], -- j)
                stl[j][ti + t[j]] = 1;
        }

        printf("Case Number %d: ", ++ tCase);

        for(int i = 1; i < N; ++ i)
            dp[i][T] = INF;

        dp[N][T] = 0;

        for(int j = T - 1; j >= 0; -- j)
            for(int i = 1; i <= N; ++ i)
            {
                dp[i][j] = dp[i][j + 1] + 1;

                if(i < N && stf[i][j] && j + t[i] <= T)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + t[i]]);

                if(i > 1 && stl[i][j] && j + t[i - 1] <= T)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + t[i - 1]]);
            }

        if(dp[1][0] >= INF)
            puts("impossible");
        else
            printf("%d\n", dp[1][0]);
    }

    return 0;
}