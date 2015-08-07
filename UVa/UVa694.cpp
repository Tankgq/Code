#include <iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	for(int tCase = 1; ; ++ tCase)
	{
		long long A, limit;
		cin >> A >> limit;
		if(A == -1 && limit == -1)
			break;
		int ret = 0;
		long long tmp = A;
		if(tmp < limit)
			while(++ ret && tmp != 1)
				if(tmp % 2 == 0)
					tmp /= 2;
				else
				{
					tmp = 3 * tmp + 1;
					if(tmp > limit)
						break;
				}
		cout << "Case " << tCase << ": A = " << A << ", limit = "
		     << limit << ", number of terms = " << ret << endl;
	}
	return 0;
}