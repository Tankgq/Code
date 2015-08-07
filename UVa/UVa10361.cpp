#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 100 + 5;

char str1[MAXN];
char str2[MAXN];

void ans()
{
    char *p1 = strchr(str1, '<');
    char *q1 = strchr(p1, '>');
    char *p2 = strchr(q1, '<');
    char *q2 = strchr(p2, '>');
    char *end = strchr(q2, ' ');
    char *k = strstr(str2, "...");

    if(end == NULL)
        end = strchr(q2, '\0');

    for(char *pi = str1; pi < p1; ++pi)
        putchar(*pi);

    for(char *pi = p1 + 1; pi < q1; ++pi)
        putchar(*pi);

    for(char *pi = q1 + 1; pi < p2; ++pi)
        putchar(*pi);

    for(char *pi = p2 + 1; pi < q2; ++pi)
        putchar(*pi);

    for(char *pi = q2 + 1; *pi != '\0'; ++pi)
        putchar(*pi);

    putchar('\n');

    for(char *pi = str2; pi < k; ++pi)
        putchar(*pi);

    for(char *pi = p2 + 1; pi < q2; ++pi)
        putchar(*pi);

    for(char *pi = q1 + 1; pi < p2; ++pi)
        putchar(*pi);

    for(char *pi = p1 + 1; pi < q1; ++pi)
        putchar(*pi);

    for(char *pi = q2 + 1; pi < end; ++pi)
        putchar(*pi);

    for(char *pi = k + 3; *pi != '\0'; ++pi)
        putchar(*pi);

    putchar('\n');
}

int main()
{
    int tCase;
    scanf("%d\n", &tCase);

    while(tCase--)
    {
        gets(str1);
        gets(str2);
        ans();
    }

    return 0;
}

/*
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;

string s, s1, s2, s3, s4, s5;

int main()
{
    //cin.sync_with_stdio(false);
    int tc;
    cin >> tc;
    getchar();

    while(tc--)
    {
        getline(cin, s1, '<');
        getline(cin, s2, '>');
        getline(cin, s3, '<');
        getline(cin, s4, '>');
        getline(cin, s5, '\n');
        getline(cin, s, '\n');
        cout << s1 << s2 << s3 << s4 << s5 << endl;
        s.erase(s.end() - 3, s.end());
        cout << s << s4 << s3 << s2 << s5 << endl;
    }

    return 0;
}*/