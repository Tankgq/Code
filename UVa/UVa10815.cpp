#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<string>
#include<cstdio>
#include<ctype.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 200 + 5;

string str;
char tmp[MAXN];
set<string> dictionary;

inline void Print(string str)
{
	int len = str.length();

	for(int i = 0; i < len; ++ i)
		putchar(str[i]);

	putchar('\n');
}

int main()
{
	cin.sync_with_stdio(false);
	char ch;
	int i = -1;

	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
			tmp[++i] = tolower(ch);
		else
		{
			tmp[++i] = '\0';

			if(i == 0)
			{
				i = -1;
				continue;
			}

			i = -1;
			str = tmp;
			dictionary.insert(str);
		}
	}

	for_each(dictionary.begin(), dictionary.end(), Print);
	return 0;
}