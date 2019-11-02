#include <array>
#include <iostream>

class Matrix {
public:
    std::array<std::array<long, 2>, 2> m;

    Matrix()
    {
        this->m[0][0] = 1;
        this->m[0][1] = 1;
        this->m[1][0] = 1;
        this->m[1][1] = 0;
    }

    Matrix(const Matrix &x) { this->m = x.m; }

    void multiply(const Matrix &x)
    {
        static Matrix y;
        y.m[0][0] =
            (this->m[0][0] * x.m[0][0] + this->m[0][1] * x.m[1][0]) % (1 << 20);
        y.m[0][1] =
            (this->m[0][0] * x.m[0][1] + this->m[0][1] * x.m[1][1]) % (1 << 20);
        y.m[1][0] =
            (this->m[1][0] * x.m[0][0] + this->m[1][1] * x.m[1][0]) % (1 << 20);
        y.m[1][1] =
            (this->m[1][0] * x.m[0][1] + this->m[1][1] * x.m[1][1]) % (1 << 20);
        this->m = y.m;
    }

    long get_value(int mod) { return this->m[0][0] % (mod ? (1 << mod) : 1); }
};

int main(void)
{
    int                    n, m;
    std::array<Matrix, 21> table;
    table[0] = Matrix();
    for (int i = 1; i < 21; ++i) {
        table[i] = Matrix(table[i - 1]);
        table[i].multiply(table[i]);
    }
    while (std::cin >> n >> m) {
        if (m < 1) {
            std::cout << "0" << std::endl;
            continue;
        }
        n %= 3 * (1 << m);
        if (n < 3) {
            std::cout << (n < 1 ? 0 : 1) << std::endl;
            continue;
        }
        Matrix ans;
        int    exp = 0;
        n -= 2;
        while (n) {
            if (n & 1) ans.multiply(table[exp]);
            ++exp;
            n >>= 1;
        }
        std::cout << ans.get_value(m) << std::endl;
    }

    return 0;
}
