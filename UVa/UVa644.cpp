#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<cstdio>
const int MAXLEN = 10 + 5;
const int MAXN = (2 << 10) + 5;

int n = 0;
int tCase = 1;
char binaryCode[MAXN][MAXLEN];

bool Is_Prefix(char *str, char *sub)
{
	int len = strlen(str);
	int sublen = strlen(sub);

	if(len < sublen)
		return false;
	else if(len == sublen)
		return (strcmp(str, sub) == 0);

	for(int i = 0; i < sublen; ++ i)
		if(str[i] != sub[i])
			return false;

	return true;
}

void ans()
{
	printf("Set %d is ", tCase);

	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < n; ++ j)
			if(i != j && Is_Prefix(binaryCode[i], binaryCode[j]))
			{
				puts("not immediately decodable");
				return;
			}

	puts("immediately decodable");
}

int main()
{
	while(gets(binaryCode[n++]) != NULL)
		if(binaryCode[n - 1][0] == '9')
		{
			ans();
			n = 0;
			++tCase;
		}

	return 0;
}