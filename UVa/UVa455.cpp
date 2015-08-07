#include <iostream>
#include <string>
using namespace std;


int main()
{
	int t;
	cin.sync_with_stdio(false);
	cin >> t;
	while(t --)
	{
		bool flag;
		int k = 1;
		string str;
		cin >> str;
		int len = str.length();
		for(k = 1; k <= len; ++ k)
			if(len % k == 0)
			{
				flag = true;
				int i = 0, j = i + k;
				for(int i = k; i < len; ++ i)
					if(str[i] != str[ i % k ])
					{
						flag = false;
						break;
					}
				if(flag)
				{
					cout << k << endl;
					if(t)
						cout << endl;
					break;
				}
			}
	}
	return 0;
}