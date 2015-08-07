#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<ctype.h>
const int MAXN = 50 + 5;

int n, m, k;
char map[MAXN][MAXN];
int dir_x[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dir_y[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool Equal(char ch1, char ch2)
{
    if(toupper(ch1) == toupper(ch2))
        return true;

    return false;
}

void Find_Word(char *str)
{
    int k;
    int len = strlen(str);

    for(int i = 0; i < n; ++ i)
        for(int j = 0; j < m; ++ j)
            if(Equal(str[0], map[i][j]))
                for(int d = 0; d < 8; ++ d)
                {
                    if((d == 3 || d == 4) && (i + 1) < len)
                        continue;
                    else if(d == 5 && (i + 1) < len && (j + 1) < len)
                        continue;
                    else if((d == 6 || d == 7) && (j + 1) < len)
                        continue;

                    for(k = 1; k < len; ++k)
                    {
                        int xx = i + k * dir_x[d];
                        int yy = j + k * dir_y[d];

                        if(xx < 0 || xx >= n || yy < 0 || yy >= m || Equal(str[k], map[xx][yy]) == false)
                            break;
                    }

                    if(k == len)
                    {
						printf("%d %d\n", i + 1, j + 1);
                        return;
                    }
                }
}

int main()
{
    int tCase;
    char str[MAXN];
    scanf("%d", &tCase);

    while(tCase --)
    {
        scanf("%d%d\n", &n, &m);

        for(int i = 0; i < n; ++ i)
            gets(map[i]);

        scanf("%d\n", &k);

        for(int i = 0; i < k; ++ i)
        {
            gets(str);
            Find_Word(str);
        }

		if (tCase)
			putchar('\n');
    }

    return 0;
}