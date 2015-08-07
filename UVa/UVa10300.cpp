#include<stdio.h>

int main()
{
    int n;
    scanf( "%d", &n );
    while( n -- )
    {
        int f;
        int a, b, c;
        long long sum = 0;
        scanf( "%d", &f );
        for( int i = 0; i < f; ++ i )
        {
            scanf( "%d%d%d", &a, &b, &c );
            sum += a * c;
        }
        printf( "%lld\n", sum );
    }
    return 0;
}
