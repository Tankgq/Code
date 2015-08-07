#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 2001;

class Bgin
{
public:
    int len;
    char bgin[840];

    Bgin()
    {
        this->len = 0;
        memset(this->bgin, '0', sizeof(this->bgin));
    }

    Bgin operator + (const Bgin &x) const
    {
        Bgin res;
        int m, r = 0;
        res.len = this->len > x.len ? this->len : x.len;

        for(int i = 0; i <= res.len; ++ i)
        {
            m = (this->bgin[i] - '0') + (x.bgin[i] - '0') + r;
            res.bgin[i] += m % 10;
            r = m / 10;
        }

        if(r)
            res.bgin[++ res.len] += r;

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
Bgin ans[MAXN], s[MAXN];

int main()
{
    s[1].bgin[0] = '2';
    ans[1].bgin[0] = '1';

    for(int i = 2; i < MAXN; ++ i)
    {
        ans[i] = ans[i - 1] + s[i - 1];
        s[i] = s[i - 1] + ans[i];
    }

    while(~scanf("%d", &n) && n)
        ans[n].display();

    return 0;
}

