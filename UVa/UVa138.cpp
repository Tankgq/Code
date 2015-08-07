#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
//const int MAXN = 90000000 + 5;

//LL f[MAXN];
int ans[10][2] = { 6, 8, 35, 49, 204, 288, 1189, 1681, 6930, 9800, 40391, 57121, 235416 ,
				   332928, 1372105, 1940449, 7997214, 11309768, 46611179 , 65918161
				 };

// int search(LL key)
// {
//  int mid;
//  int left = 1;
//  int right = MAXN - 1;
//
//  if(key == 1)
//      return 1;
//
//  if(key == MAXN - 1)
//      return MAXN - 1;
//
//  while(left <= right)
//  {
//      mid = left + ((right - left) >> 1);
//
//      if(f[mid] == key)
//          return mid;
//
//      if(f[mid] > key)
//          right = mid - 1;
//      else
//          left = mid + 1;
//  }
//
//  return -1;
// }

int main()
{
//  int t = 0;
//  f[0] = 0;
//
//  for(int i = 1; i < MAXN; ++ i)
//      f[i] = f[i - 1] + i;
//
//  for(int m = 2; m < MAXN && t < 10; ++m)
//  {
//      LL l = search(f[m] + f[m - 1]);
//
//      if(l != -1)
//      {
//          ++t;
//          cout << m << ' ' << l << endl;
//      }
//  }
	for(int i = 0; i < 10; ++i)
		printf("%10d%10d\n", ans[i][0], ans[i][1]);

	//Åå¶û·½³Ì
	/*int j, x1, y1, x, y, newx, newy;
	x = x1 = 3, y = y1 = 1;
	for (int i = 0; i < 10; i++)
	{
		newx = x * x1 + 8 * y * y1;
		newy = y * x1 + x * y1;
		x = newx, y = newy;
		printf("%10d%10d\n", y, (x - 1) / 2);
	}*/


	return 0;
}
