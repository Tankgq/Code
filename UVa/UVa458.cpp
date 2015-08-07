#include<stdio.h>

int main()
{
    char ch;
    while( (ch = getchar() ) != EOF )
        if( ch != '\n' )
            putchar( ch - 7 );
        else
            putchar( ch );
    return 0;
}
