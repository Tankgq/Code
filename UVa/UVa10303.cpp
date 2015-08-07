/*
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int LEN = 5;
const int MAXN = 1001;

void Swap(char &x, char &y)
{
    char tmp = x;
    x = y;
    y = tmp;
}

void Reverse(char *x, int st, int en)
{
    int len = en - st;

    if(len == 0)
        return;

    for(int i = len >> 1; i >= 0; -- i)
        Swap(x[st + i], x[en - i]);
}

class Bgin
{
public:
    int len;
    char bgin[MAXN];

    Bgin()
    {
        this->len = 0;
        memset(this->bgin, '0', sizeof(bgin));
    }

    Bgin operator * (const int x) const
    {
        Bgin res;
        int tt, tmp = 0;
        res.len = this->len;

        for(int i = 0; i <= res.len; ++ i)
        {
            tt = tmp + (this->bgin[i] - '0') * x;
            res.bgin[i] += tt % 10;
            tmp = tt / 10;
        }

        while(tmp)
        {
            res.bgin[++ res.len] += tmp % 10;
            tmp /= 10;
        }

        return res;
    }

    Bgin operator / (const int x) const
    {
        Bgin res;
        res.len = -1;
        int tLen = this->len;
        int i, tmp = 0, mod = 1, d, dLen, r = 0;

        for(int i = 0; i < LEN && (tLen >= 0); ++ i, -- tLen, mod *= 10)
            tmp = tmp * 10 + this->bgin[tLen] - '0';

        d = tmp / x, r = tmp % x;

        while(d)
        {
            res.bgin[++ res.len] += d % 10;
            d /= 10;
        }

        Reverse(res.bgin, 0, res.len);

        while(tLen >= 0)
        {
            mod = 1, tmp = 0;
            dLen = res.len + 1;

            for(i = 0; i < LEN && (tLen >= 0); ++ i, -- tLen, mod *= 10)
                tmp = tmp * 10 + this->bgin[tLen] - '0';

            if(r)
                tmp += r * mod;

            d = tmp / x, r = tmp % x;

            while(d)
            {
                res.bgin[++ res.len] += d % 10;
                d /= 10;
            }

            res.len = dLen + i - 1;
            Reverse(res.bgin, dLen, res.len);
        }

        Reverse(res.bgin, 0, res.len);
        return res;
    }

    void display()
    {
        for(int i = this->len; i >= 0; -- i)
            putchar(this->bgin[i]);

        putchar('\n');
    }
};

int n;
Bgin catalan[MAXN];

int main()
{
    catalan[1].bgin[0] = '1';

    for(int i = 2; i < MAXN; ++ i)
        catalan[i] = catalan[i - 1] * ((i << 2) - 2) / (i + 1);

    while(~scanf("%d", &n))
        catalan[n].display();

    return 0;
}*/

#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int D = 9;
typedef long long LL;
const int MAXN = 1000 + 5;
const int MAXSIZE = 100 + 5;
const LL BASE = 1000000000LL;
#define max(a, b) (a) > (b) ? (a) : (b)

class Bgin
{
public:
    int len;
    LL data[MAXSIZE];

    Bgin()
    {
        this->len = 0;
        memset(this->data, 0, sizeof(this->data));
    }

    Bgin operator + (const Bgin &x) const
    {
        Bgin res;
        LL tt, tmp = 0;
        res.len = max(x.len, this->len);

        for(int i = 0; i <= res.len; ++ i)
        {
            tt = this->data[i] + x.data[i] + tmp;
            res.data[i] = tt % BASE;
            tmp = tt / BASE;
        }

        if(tmp)
            res.data[++ res.len] = tmp;

        return res;
    }

    Bgin operator * (const int &x) const
    {
        Bgin res;
        LL tt, tmp = 0;
        res.len = this->len;

        for(int i = 0; i <= res.len; ++ i)
        {
            tt = this->data[i] * x + tmp;
            res.data[i] = tt % BASE;
            tmp = tt / BASE;
        }

        while(tmp)
        {
            res.data[++ res.len] = tmp % BASE;
            tmp /= BASE;
        }

        return res;
    }

    //©иртуШЁЩ,гр x <= BASE
    Bgin operator / (const int &x) const
    {
        Bgin res;
        LL s, r = 0;
        res.len = this->len;

        for(int i = res.len; i >= 0; -- i)
        {
            s = r * BASE + this->data[i];
            res.data[i] = s / x;
            r = s % x;
        }

        for(int i = res.len; i > 0; -- i)
            if(! res.data[i])
                -- res.len;
            else
                break;

        return res;
    }

    void display()
    {
        printf("%lld", this->data[this->len]);

        for(int i = this->len - 1; i >= 0; -- i)
            printf("%09lld", this->data[i]);

        putchar('\n');
    }
};

int n;
Bgin catalan[MAXN];

int main()
{
    catalan[1].data[0] = 1;

    for(int i = 2; i < MAXN; ++ i)
        catalan[i] = catalan[i - 1] * ((i << 2) - 2) / (i + 1);

    while(~scanf("%d", &n))
        catalan[n].display();

    return 0;
}