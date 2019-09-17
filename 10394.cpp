#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int lenL, lenP, prime[620], list[100000];

bool isPrime(int x)
{
    int i, next;
    int bound = (int)sqrt((double)x);

    for (i = 0; prime[i] <= bound; ++i)
        if (x % prime[i] == 0) return false;

    return true;
}

int main(void)
{
    bool flag;
    int  i, next, n;

    lenL     = 0;
    lenP     = 1;
    prime[0] = 3;

    while (prime[lenP - 1] < 4500) {
        prime[lenP] = prime[lenP - 1] + 2;
        while (!isPrime(prime[lenP]))
            prime[lenP] += 2;
        if (prime[lenP] == prime[lenP - 1] + 2) list[lenL++] = prime[lenP - 1];
        lenP++;
    }

    next = prime[lenP - 1];
    flag = true;
    while (lenL < 100000) {
        if (flag || isPrime(next)) {
            flag = isPrime(next + 2);
            if (flag)
                list[lenL++] = next;
            else
                next += 2;
        }
        next += 2;
    }

    while (scanf("%d", &n) != EOF) {
        n--;
        printf("(%d, %d)\n", list[n], list[n] + 2);
    }

    return 0;
}
