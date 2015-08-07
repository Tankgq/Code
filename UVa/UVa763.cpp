#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 100 + 5;

class Bgin
{
public:
    int len;
    char bgin[MAXN];

    Bgin()
    {
        this->len = 0;
        memset(this->bgin, '0', sizeof(this->bgin));
    }

    Bgin operator + (const Bgin &x) const
    {
        Bgin res;
        int tt, temp = 0;
        res.len = this->len > x.len ? this->len : x.len;

        for(int i = 0; i <= res.len; ++ i)
        {
            tt = temp + (this->bgin[i] - '0') + (x.bgin[i] - '0');
            res.bgin[i] += tt % 10;
            temp = tt / 10;
        }

        if(temp)
            res.bgin[++ res.len] = temp + '0';

        return res;
    }

    Bgin operator - (const Bgin &x) const
    {
        Bgin res;
        res.len = this->len;

        for(int i = 0; i <= this->len; ++ i)
            res.bgin[i] = this->bgin[i] - (x.bgin[i] - '0');

        for(int i = 0; i < this->len; ++ i)
            if(res.bgin[i] < '0')
            {
                res.bgin[i] += 10;
                -- res.bgin[i + 1];
            }

        for(int i = res.len; i > 0; -- i)
            if(res.bgin[i] == '0')
                -- res.len;
            else
                break;

        return res;
    }

    bool operator >= (const Bgin &x) const
    {
        if(this->len == x.len)
        {
            for(int i = x.len; i >= 0; -- i)
                if(this->bgin[i] != x.bgin[i])
                    return this->bgin[i] > x.bgin[i];

            return true;
        }

        return this->len > x.len;
    }
};

Bgin fibs[480];
char x1[MAXN], x2[MAXN], ans[MAXN];

void SetBgin(Bgin &x, char *str1, char *str2)
{
    int len = strlen(str1) - 1;

    for(int i = len; i >= 0; -- i, ++ str1)
        if(*str1 == '1')
            x = x + fibs[i];

    len = strlen(str2) - 1;

    for(int i = len; i >= 0; -- i, ++ str2)
        if(*str2 == '1')
            x = x + fibs[i];
}

void ToFibinary(Bgin &x)
{
    int index = x.len * 5 + 4;

    for(int i = index; x.bgin[0] != '0' || x.len; -- i)
        if(x >= fibs[i])
        {
            ans[i] = '1';
            x = x - fibs[i];
        }

    for(int i = index; i > 0; -- i)
        if(ans[i] == '1')
        {
            for(int j = i; j >= 0; -- j)
                putchar(ans[j]);

            putchar('\n');
            return;
        }

    puts("0");
}

int main()
{
    fibs[0].bgin[0] = '1';
    fibs[1].bgin[0] = '2';

    for(int i = 2; i < 480; ++ i)
        fibs[i] = fibs[i - 1] + fibs[i - 2];

    //while(~scanf("%s%s", x1, x2));
    while(gets(x1) && gets(x2))
    {
        Bgin a;
        memset(ans, '0', sizeof(ans));
        SetBgin(a, x1, x2);
        ToFibinary(a);

        if(getchar() != EOF)
            putchar('\n');
    }

    return 0;
}