#include<ios>
#include<map>
#include<set>
#include<list>
#include<cmath>
#include<ctime>
#include<deque>
#include<stack>
#include<queue>
#include<bitset>
#include<cctype>
#include<cerrno>
#include<cstdio>
#include<cwchar>
#include<iosfwd>
#include<limits>
#include<memory>
#include<string>
#include<vector>
#include<clocale>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<cwctype>
#include<fstream>
#include<iomanip>
#include<numeric>
#include<sstream>
#include<utility>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<exception>
#include<stdexcept>
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

LL N;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\ηχ\\Desktop\\in.txt", "r", stdin);
	//freopen("C:\\Users\\ηχ\\Desktop\\out.txt", "w", stdout);
#endif

	while(~scanf("%lld", &N) && ~(N >> 31))
		printf("%lld\n", (N * (N + 1) >> 1) + 1);

	return 0;
}