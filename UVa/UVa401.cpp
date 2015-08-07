#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1000 + 5;

int main()
{
    cin.sync_with_stdio(false);
    char str[MAXN];
    char num[11] = { "*1SE*Z**8*" };
    int palidrome, morrioed, choices;
    char alp[27] = { "A***3**HIL*JM*O***2TUVWXY5" };
    char ans[4][30] = { " -- is not a palindrome.", " -- is a regular palindrome.", " -- is a mirrored string.", " -- is a mirrored palindrome." };

    while(gets(str) != NULL)
    {
        int len = strlen(str);
        palidrome = morrioed = 1;

        if(len == 1)
        {
            if(isalpha(str[0]))
            {
                if(alp[str[0] - 'A'] != str[0])
                    morrioed = 0;
            }
            else
            {
                if(num[str[0] - '0'] != str[0])
                    morrioed = 0;
            }
        }
        else
        {
            for(int i = 0; i < len / 2; ++i)
                if(str[i] != str[len - i - 1])
                {
                    palidrome = 0;
                    break;
                }

            for(int i = 0; i < len / 2; ++i)
            {
                if(isalpha(str[i]))
                {
                    if(alp[str[i] - 'A'] != str[len - i - 1])
                    {
                        morrioed = 0;
                        break;
                    }
                }
                else
                {
                    if(num[str[i] - '0'] != str[len - i - 1])
                    {
                        morrioed = 0;
                        break;
                    }
                }
            }
        }

        if(!palidrome && !morrioed)
            choices = 0;
        else if(palidrome && !morrioed)
            choices = 1;
        else if(!palidrome && morrioed)
            choices = 2;
        else
            choices = 3;

        printf("%s%s\n\n", str, ans[choices]);
    }

    return 0;
}
