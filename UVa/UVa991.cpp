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
const int MAXN = 5e5 + 5;
typedef unsigned int uInt;
const int INF = 0x7FFFFFFF;
const double PI = acos(-1.0);
typedef unsigned long long uLL;
const LL INF_LL = 0x7FFFFFFFFFFFFFFFLL;

int N;
int dp[16];
int ans[] = {0, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};

// 由于直线不能相交
// 每次选择一对点
// 那么剩下的分别可以配对为
// 0 和 n - 1, 1 和  n - 2, ... n - 1 和 0
void prepare() {
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(int i = 1; i <= 10; ++ i)
	for(int j = 0; j < i; ++ j)
		dp[i] += dp[j] * dp[i - j - 1];
}

int main() {
#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\琪\\Desktop\\in.txt", "r", stdin);
	//freopen("C:\\Users\\琪\\Desktop\\out.txt", "w", stdout);
#endif
	prepare();
	bool st = false;

	while(~scanf("%d", &N)) {
		if(st)
			puts("");

		printf("%d\n", dp[N]);
		st = true;
	}

	return 0;
}