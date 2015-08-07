#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int tCase;
    int DNA[15];
    int ansdish[45] = { 0 };
    int tmpdish[45] = { 0 };
    int initdish[45] = { 0 };
    char level[4] = { ' ', '.', 'x', 'W' };
    initdish[20] = 1;
    scanf("%d", &tCase);

    while(tCase--)
    {
        memcpy(ansdish, initdish, 180);

        for(int i = 0; i < 10; ++i)
            scanf("%d", DNA + i);

        for(int k = 0; k < 50; ++ k)
        {
            for(int cd = 1; cd < 41; ++cd)
                putchar(level[ansdish[cd]]);

            putchar('\n');

            for(int i = 1; i < 41; ++i)
                tmpdish[i] = DNA[ansdish[i - 1] + ansdish[i] + ansdish[i + 1]];

            memcpy(ansdish, tmpdish, 180);
        }

        if(tCase != 0)
            cout << endl;
    }

    return 0;
}