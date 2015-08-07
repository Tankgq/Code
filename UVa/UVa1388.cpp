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
const int MAXN = 1e5 + 5;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
typedef unsigned long long uLL;

int n, m;
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
#endif

    while(~scanf("%d%d", &n, &m))
    {
        ans = 0.0;

        for(int i = 1; i < n; ++ i)
        {
            double pos = (double)i / n * (n + m);
            ans += fabs(pos - floor(pos + 0.5));
        }

        printf("%.4lf\n", ans * 10000 / (m + n));
    }

    return 0;
}