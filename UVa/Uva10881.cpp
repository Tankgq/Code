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
const int MAXN = 1e4 + 5;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
typedef unsigned long long uLL;

class Ant
{
public:
    int dir, loc, ind;
};

Ant ants[MAXN];
int n, L, t, tind[MAXN];
char statu[5][10] = {"L", "Turning", "R"};

bool cmp_loc(const Ant &a, const Ant &b)
{
    return a.loc < b.loc;
}

bool cmp_ind(const Ant &a, const Ant &b)
{
    return a.ind < b.ind;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);

    for(int tCase = 1; tCase <= T; ++ tCase)
    {
        scanf("%d%d%d", &L, &t, &n);

        for(int i = 0; i < n; ++ i)
        {
            scanf("%d ", &ants[i].loc);
            char op = getchar();
            ants[i].ind = i;
            ants[i].dir = (op == 'L') ? -1 : 1;
        }

        sort(ants, ants + n, cmp_loc);

        for(int i = 0; i < n; ++ i)
            ants[i].loc += ants[i].dir * t, ants[i].dir, tind[i] = ants[i].ind;

        sort(ants, ants + n, cmp_loc);

        for(int i = 0; i < n; ++ i)
            ants[i].ind = tind[i];

        for(int i = 1; i < n; ++ i)
            if(ants[i - 1].loc == ants[i].loc)
                ants[i - 1].dir = ants[i].dir = 0;

        sort(ants, ants + n, cmp_ind);
        printf("Case #%d:\n", tCase);

        for(int i = 0; i < n; ++ i)
        {
            if(ants[i].loc < 0 || ants[i].loc > L)
                puts("Fell off");
            else
                printf("%d %s\n", ants[i].loc, statu[ants[i].dir + 1]);
        }

        putchar('\n');
    }

    return 0;
}