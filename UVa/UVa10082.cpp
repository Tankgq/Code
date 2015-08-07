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
const int MAXN = 1e3 + 5;
typedef unsigned int uInt;
const int INF = 0x7FFFFFFF;
const double PI = acos (-1.0);
typedef unsigned long long uLL;
const LL INF_LL = 0x7FFFFFFFFFFFFFFFLL;

char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
char val[256];
char ch;


int main () {
#ifndef ONLINE_JUDGE
	//freopen("C:/Users/Tank/Desktop/in.txt", "r", stdin);
	//freopen("C:/Users/Tank/Desktop/out.txt", "w", stdout);
#endif

	for (int i = 1; i < 49; ++ i)
		val[key[i]] = key[i - 1];

	val['\n'] = '\n';
	val[' '] = ' ';

	while (~(ch = getchar ())) {
		putchar (val[ch]);
	}

	return 0;
}
