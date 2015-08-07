#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<stack>
#include<queue>
#include<cctype>
#include<cstdio>
#include<bitset>
#include<memory>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<utility>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const double EPS = 1e-12;
const int MAXN = 5e2 + 5;
typedef unsigned int uInt;
const int INF = 0x7FFFFFFF;
const double PI = acos(-1.0);
typedef unsigned long long uLL;
const LL INF_LL = 0x7FFFFFFFFFFFFFFFLL;

int N, ind;
double p, ans;
// dp[][i][j] 表示最多连胜 i 场时
// 从最后一场开始算起连胜次数为 j 的概率
double dp[2][MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\琪\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\琪\\Desktop\\out.txt", "w", stdout);
#endif

    while(~scanf("%d%lf", &N, &p) && N) {
        memset(dp, 0, sizeof(dp));
        ind = 0, ans = 0.0, dp[0][1][1] = p, dp[0][0][0] = 1 - p;

        for(int cnt = 2; cnt <= N; ++ cnt, ind = 1 - ind) {
            // 0 == i
            dp[1 - ind][0][0] = dp[ind][0][0] * (1 - p);

            for(int i = 1; i <= cnt; ++ i) {
                // 0 == j
                double tmp = 0.0;

                for(int k = 0; k <= i; ++ k)
                    tmp += dp[ind][i][k];

                dp[1 - ind][i][0] = tmp * (1 - p);

                // i > j
                for(int j = 1; j < i; ++ j)
                    dp[1 - ind][i][j] = dp[ind][i][j - 1] * p;

                // i == j
                dp[1 - ind][i][i] = (dp[ind][i][i - 1] + dp[ind][i - 1][i - 1]) * p;
            }
        }

        for(int i = 1; i <= N; ++ i)
            for(int j = 0; j <= i; ++ j)
                ans += i * dp[ind][i][j];

        printf("%.6lf\n", ans);
    }

    return 0;
}
/*
#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<stack>
#include<queue>
#include<cctype>
#include<cstdio>
#include<bitset>
#include<memory>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<utility>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7;
const double EPS = 1e-12;
const int MAXN = 5e2 + 5;
typedef unsigned int uInt;
const int INF = 0x7FFFFFFF;
const double PI = acos(-1.0);
typedef unsigned long long uLL;
const LL INF_LL = 0x7FFFFFFFFFFFFFFFLL;

int N;
double p, ans;
double fact[MAXN];
// dp[i][j] 表示比赛进行到第 i 场时
// 连胜次数小于等于 j 场的概率
double dp[MAXN][MAXN];

int main() {
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\琪\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\琪\\Desktop\\out.txt", "w", stdout);
#endif
    fact[0] = 1.0;

    for(int i = 0; i <= 500; ++ i)
        dp[0][i] = 1.0;

    while(~scanf("%d%lf", &N, &p) && N) {
        ans = 0.0;

        for(int i = 1; i <= N; ++ i)
            fact[i] = fact[i - 1] * p;

        for(int i = 1; i <= N; ++ i) {
            for(int j = 0; j < i - 1; ++ j)
                dp[i][j] = dp[i - 1][j] - dp[i - j - 2][j] * (1 - p) * fact[j + 1];

            dp[i][i - 1] = 1 - fact[i];

            for(int j = i; j <= N; ++ j)
                dp[i][j] = dp[i - 1][j];
        }

        //      for(int j = 1; j <= N; ++ j)
        //          ans += dp[N][j] - dp[N][j - 1];

        for(int j = 0; j < N; ++ j)
            ans += dp[N][j];

        printf("%.6lf\n", N - ans);
    }

    return 0;
}*/