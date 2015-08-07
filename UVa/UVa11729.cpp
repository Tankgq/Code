#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3 + 5;
#define max(a, b) (a) > (b) ? a : b

class Task
{
public:
    int pre, uset;
};

int N, ans;
Task tas[MAXN];

bool cmp(const Task &a, const Task &b)
{
    return a.uset > b.uset;
}

int main()
{
    int tCase = 0;

    while(~scanf("%d", &N) && N)
    {
        ans = 0;

        for(int i = 0; i < N; ++ i)
        {
            scanf("%d%d", &tas[i].pre, &tas[i].uset);
            ans += tas[i].pre;
        }

        sort(tas, tas + N, cmp);

        for(int i = 0, tans = tas[0].pre; i < N; ++ i, tans += tas[i].pre)
            ans = max(ans, tans + tas[i].uset);

        printf("Case %d: %d\n", ++ tCase, ans);
    }

    return 0;
}