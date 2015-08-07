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
const int MAXN = 1e1 + 5;
const int INF = 0x7fffffff;
const double PI = acos(-1.0);
typedef unsigned long long uLL;

int N, ans;
int x, y, z;
char cube[15][15][15];
char views[10][15][15];

void change_to(int k, int i, int j, int depth)
{
	switch(k)
	{
		case 0:
			x = j, y = depth, z = i;
			return;

		case 1:
			x = depth, y = N - j - 1, z = i;
			return;

		case 2:
			x = N - j - 1, y = N - depth - 1, z = i;
			return;

		case 3:
			x = N - depth - 1, y = j, z = i;
			return;

		case 4:
			x = j, y = N - i - 1, z = depth;
			return;

		case 5:
			x = j, y = i, z = N - depth - 1;
			return;
	}
}

void update()
{
	bool doNothing = true;

	for(int k = 0; k < 6; ++ k)
		for(int i = 0; i < N; ++ i)
			for(int j = 0; j < N; ++ j)
				if(views[k][i][j] != '.')
					for(int d = 0; d < N; ++ d)
					{
						change_to(k, i, j, d);

						if('.' == cube[x][y][z])
							continue;

						if('*' == cube[x][y][z])
						{
							cube[x][y][z] = views[k][i][j];
							break;
						}

						if(views[k][i][j] == cube[x][y][z])
							break;

						cube[x][y][z] = '.';
						doNothing = false;
					}

	if(false == doNothing)
		update();
}

int main()
{
#ifndef ONLINE_JUDGE
	//freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	//freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
#endif

	while(scanf("%d", &N), N)
	{
		getchar();
		ans = N * N * N;
		memset(cube, '*', sizeof(cube));

		for(int i = 0; i < N; ++ i)
			for(int k = 0; k < 6; ++ k, getchar())
				for(int j = 0; j < N; ++ j)
				{
					views[k][i][j] = getchar();

					if(views[k][i][j] == '.')
						for(int d = 0; d < N; ++ d)
						{
							change_to(k, i, j, d);
							cube[x][y][z] = '.';
						}
				}

		update();

		for(int x = 0; x < N; ++ x)
			for(int y = 0; y < N; ++ y)
				for(int z = 0; z < N; ++ z)
					if(cube[x][y][z] == '.')
						-- ans;

		printf("Maximum weight: %d gram(s)\n", ans);
	}

	return 0;
}