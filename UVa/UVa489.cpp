#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char ch;
	int tCase;
	int alphabet[26];
	while(scanf("%d", &tCase) && tCase != -1)
	{
		getchar();
		int num = 0;
		int wrong = 0;
		bool flag = false;
		memset(alphabet, 0, sizeof(alphabet));
		while((ch = getchar()) != '\n')
			if(!alphabet[ ch - 'a' ])
			{
				alphabet[ ch - 'a' ] = 1;
				++ num;
			}
		while((ch = getchar()) != '\n')
			if(flag == 0 && wrong < 7)
			{
				if(alphabet[ ch - 'a' ] == 1)
				{
					alphabet[ ch - 'a' ] = 0;
					-- num;
					if(num == 0)
						flag = true;
				}
				else
					++ wrong;
//              else if(alphabet[ ch - 'a' ] == 0)
//              {
//                  ++ wrong;
//                  alphabet[ ch - 'a' ] = -1;
//              }
//              else if(alphabet[ ch - 'a' ] == -2)
//              {
//                  ++ wrong;
//                  alphabet[ ch - 'a' ] = -1;
//              }
			}
		printf("Round %d\n", tCase);
		if(flag)
			puts("You win.");
		else if(wrong >= 7)
			puts("You lose.");
		else
			puts("You chickened out.");
	}
	return 0;
}
