#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
const int MAXN = 1001;

class Bgin
{
public:
    int len;
    char bgin[211];

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
Bgin ans[MAXN];

int main()
{
    ans[0].bgin[0] = '1';
    ans[1].bgin[0] = '2';

    for(int i = 2; i < MAXN; ++ i)
        ans[i] = ans[i - 1] + ans[i - 2];

    while(~scanf("%d", &n))
        ans[n].display();

    return 0;
}