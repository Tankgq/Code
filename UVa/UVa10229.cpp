#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

int n, m, mod, k_mod;

class Matrix
{
public:
    int row;
    int column;
    LL data[2][2];

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
            {
                for(int k = 0; k < this->column; ++ k)
                    res.data[i][j] += this->data[i][k] * x.data[k][j];

                res.data[i][j] %= mod;
            }

        return res;
    }
};

Matrix x, t;

int solve(int k)
{
    //G(2) = 3;
    //k_mod = G(p) * p^(m - 1)
    k_mod = 3 * (1 << (m - 1));
    mod = (1 << m);
    k %= k_mod;

    if(k < 2)
        return (int)t.data[k][0];

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

    return (int)res.data[0][0];
}

int main()
{
    t.data[0][0] = 0;
    x.row = t.row = 2;
    t.column = 1, x.column = 2;
    t.data[1][0] = x.data[0][0] = 1;
    x.data[0][1] = x.data[1][0] = 1;

    while(~scanf("%d%d", &n, &m))
        printf("%d\n", solve(n));

    return 0;
}