#include<stdio.h>
const int MAXCOLUMNS = 25 + 5;
const int MAXROWS = 15 + 5;

int main()
{
    int n;
    while( scanf( "%d%*c", &n ) != EOF && n )
    {
        int sum = 0;
        char str[ MAXCOLUMNS ];
        int minNumber = 0x7FFFFFFF;
        for( int i = 0; i < n; ++ i )
        {
            gets( str );
            int count = 0;
            for( int j = 0; str[j] != '\0'; ++ j )
                if( str[j] == ' ' )
                    ++ count;
            sum += count;
            if( count < minNumber )
                minNumber = count;
        }
        printf( "%d\n", sum - minNumber * n );
    }
    return 0;
}
