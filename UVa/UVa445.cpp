#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	int number = 0;
	while((ch = getchar()) != EOF)
	{
		if(isdigit(ch))
			number += ch - '0';
		else if(isupper(ch) || ch == '*')
		{
			for(int i = 0; i < number; ++ i)
				putchar(ch);
			number = 0;
		}
		else if(ch == 'b')
		{
			for(int i = 0; i < number; ++ i)
				putchar(' ');
			number = 0;
		}
		else if(ch == '!')
			putchar('\n');
		else
			putchar(ch);
	}
	return 0;
}