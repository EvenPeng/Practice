#include <algorithm>
#include <cstdio>

using namespace std;

long gcd(long a, long b)
{
    while (a > 0 && b > 0) {
        if (a > b)
            a %= b;
        else if (a < b)
            b %= a;
        else
            return a;
    }

    return max(a, b);
}

int main(void)
{
    long n, k, result, divid, comm, i, j;

    while (scanf("%ld %ld", &n, &k) != EOF) {
        if (n == 0) break;
        if (k > n - k) k = n - k;
        if (k == 0)
            printf("1\n");
        else if (k == 1)
            printf("%ld\n", n);
        else {
            result = 1;
            divid  = 1;
            i      = n - k + 1;
            j      = k;
            while (i <= n || j >= 2) {
                while (result < 2147483648 && i <= n)
                    result *= i++;
                while (divid < 2147483648 && j >= 2)
                    divid *= j--;
                comm = gcd(result, divid);
                result /= comm;
                divid /= comm;
            }
            printf("%ld\n", result);
        }
    }

    return 0;
}
