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
const int MAXN = 2e5 + 5;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
typedef unsigned long long uLL;

int N, M;
int mx[MAXN << 2];

void build(int cur, int L, int R)
{
	if(L == R)
	{
		scanf("%d", &mx[cur]);
		return;
	}

	int mid = (R + L) >> 1;
	build(cur << 1, L, mid);
	build(cur << 1 | 1, mid + 1, R);
	mx[cur] = max(mx[cur << 1], mx[cur << 1 | 1]);
}

int query(int cur, int L, int R, int qL, int qR)
{
	if(qL <= L && R <= qR)
		return mx[cur];

	int maxL = 0, maxR = 0;
	int mid = (R + L) >> 1;

	if(qL <= mid)
		maxL = query(cur << 1, L, mid, qL, qR);

	if(qR > mid)
		maxR = query(cur << 1 | 1, mid + 1, R, qL, qR);

	return max(maxL, maxR);
}

void update(int cur, int L, int R, int loc, int val)
{
	if(L == R)
	{
		mx[cur] = val;
		return;
	}

	int mid = (R + L) >> 1;

	if(loc <= mid)
		update(cur << 1, L, mid, loc, val);
	else
		update(cur << 1 | 1, mid + 1, R, loc, val);

	mx[cur] = max(mx[cur << 1], mx[cur << 1 | 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
#endif
	
	
    return 0;
}