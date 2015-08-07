#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 480;

class Bgin
{
public:
    int len;
    char bgin[100];

    Bgin()
    {
        this->len = 0;
        memset(this->bgin, '0', sizeof(this->bgin));
    }

    Bgin(char *str)
    {
        this->len = strlen(str) - 1;
        memset(this->bgin, '0', sizeof(this->bgin));

        for(int i = this->len; i >= 0; -- i)
            this->bgin[i] = *(str ++);
    }

    Bgin operator + (const Bgin &x) const
    {
        Bgin bg;
        int tt, temp = 0;
        bg.len = this->len > x.len ? this->len : x.len;

        for(int i = 0; i <= bg.len; ++ i)
        {
            tt = temp + (this->bgin[i] - '0') + (x.bgin[i] - '0');
            bg.bgin[i] += tt % 10;
            temp = tt / 10;
        }

        if(temp)
            bg.bgin[++ bg.len] = temp + '0';

        return bg;
    }
};

Bgin fibs[MAXN];
char x1[100], x2[100];

int cmp(const Bgin &x, const Bgin &y)
{
    if(x.len == y.len)
    {
        for(int i = x.len; i >= 0; -- i)
            if(x.bgin[i] != y.bgin[i])
                return x.bgin[i] > y.bgin[i] ? 1 : -1;

        return 0;
    }

    return x.len > y.len ? 1 : -1;
}

int up(const Bgin &x)
{
    for(int i = x.len << 2; i < MAXN; ++ i)
    {
        int op = cmp(fibs[i], x);

        if(op == 1)
            return i - 1;

        if(op == 0)
            return i;
    }

    return MAXN - 1;
}

int low(const Bgin &x)
{
    if(x.len == 0 && x.bgin[0] == '0')
        return 0;

    for(int i = x.len << 2; i < MAXN; ++ i)
        if(cmp(fibs[i], x) > -1)
            return i - 1;

    return MAXN - 1;
}

int main()
{
    fibs[1].bgin[0] = '1';
    fibs[2].bgin[0] = '2';

    for(int i = 3; i < MAXN; ++ i)
        fibs[i] = fibs[i - 1] + fibs[i - 2];

    while(~scanf("%s%s", x1, x2) && !(x1[0] == '0' && x1[1] == '\0' && x2[0] == '0' && x2[1] == '\0'))
    {
        Bgin a(x1), b(x2);
        printf("%d\n", up(b) - low(a));
    }

    return 0;
}