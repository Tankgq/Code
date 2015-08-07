#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
typedef long long LL;
const int MAXN = 3;

LL n;
int mod;

class Matrix
{
public:
    int row;
    int column;
    int data[MAXN][MAXN];

    Matrix(int row = 0, int column = 0)
    {
        this->row = row;
        this->column = column;
        memset(this->data, 0, sizeof(this->data));
    }

    Matrix operator * (const Matrix &x) const
    {
        Matrix res(this->column, x.row);

        for(int i = 0; i < this->row; ++ i)
            for(int j = 0; j < this->column; ++ j)
                for(int k = 0; k < x.row; ++ k)
                    res.data[i][k] = (res.data[i][k] + this->data[i][j] * x.data[j][k]) % mod;

        return res;
    }
};

Matrix x, t;

void init()
{
    x.row = t.row = 3;
    t.column = 1, x.column = 3;
    x.data[0][0] = x.data[0][1] = 1;
    x.data[0][2] = x.data[1][0] = x.data[2][2] = 1;
    t.data[0][0] = t.data[1][0] = t.data[2][0] = 1;
}

int solve(LL k)
{
    if(k == 0LL || k == 1LL)
        return 1;

    k -= 1;
    Matrix res, tmp;
    memcpy(&res, &t, sizeof(x));
    memcpy(&tmp, &x, sizeof(t));

    while(k)
    {
        if(k & 1)
            res = tmp * res;

        k >>= 1;
        tmp = tmp * tmp;
    }

    return res.data[0][0];
}

int main()
{
    init();
    int Tcase = 0;

    while(~scanf("%lld%d", &n, &mod) && (n || mod))
        printf("Case %d: %lld %d %d\n", ++ Tcase, n, mod, solve(n));

    return 0;
}