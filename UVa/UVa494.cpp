#include<stdio.h>
#include<ctype.h>
#include<string.h>
const int MAXN = 1024 + 5;

int main()
{
    char str[ MAXN ];
    while( gets(str) != NULL )
    {
        int sum = 0;
        for( int i = 1; str[i] != '\0'; ++ i )
            if( isalpha( str[ i - 1 ] ) != 0 && isalpha( str[i] ) == 0 )
                ++ sum;
        printf( "%d\n", sum );
    }
    return 0;
}

/*
#include<stdio.h>
#include<ctype.h>
const int MAXN = 1024 + 5;

int main()
{
    char str[ MAXN ];
    while( gets(str) != NULL )
    {
        int sum = 0;
        bool flag = true;
        for( int i = 0; str[i] != '\0'; ++ i )
            if( isalpha( str[ i + 1 ] ) != 0 )
                flag = true;
            else
            {
                if( flag == true )
                    ++ sum;
                flag = false;
            }
        printf( "%d\n", sum );
    }
    return 0;
}
*/
