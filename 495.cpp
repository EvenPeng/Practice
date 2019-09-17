#include <cstdio>

using namespace std;

#define BASE 1000000000000

typedef struct bnum {
    bool flag;
    long arr[100];
} bnum;

bnum seq[5001];

void add(int sum, int a, int b)
{
    int i;

    for (i = 0; i < 100; ++i) {
        seq[sum].arr[i] += seq[a].arr[i] + seq[b].arr[i];
        if (seq[sum].arr[i] >= BASE) {
            seq[sum].arr[i + 1] += seq[sum].arr[i] / BASE;
            seq[sum].arr[i] %= BASE;
        }
    }
}

void FF(int n)
{
    if (!seq[n - 1].flag) FF(n - 1);
    if (!seq[n - 2].flag) FF(n - 2);

    add(n, n - 1, n - 2);
    seq[n].flag = true;
}

void show(int n)
{
    int i;
    if (!seq[n].flag) FF(n);

    i = 100;
    while (seq[n].arr[--i] == 0)
        if (i < 1) break;

    printf("%ld", seq[n].arr[i--]);
    for (; i > -1; --i)
        printf("%012ld", seq[n].arr[i]);
    printf("\n");
}

int main(void)
{
    int n, i;

    for (n = 0; n < 5001; ++n) {
        for (i = 0; i < 100; ++i)
            seq[n].arr[i] = 0;
        seq[n].flag = false;
    }
    for (n = 0; n < 3; ++n)
        seq[n].flag = true;
    seq[1].arr[0] = 1;
    seq[2].arr[0] = 1;

    while (scanf("%d", &n) != EOF) {
        printf("The Fibonacci number for %d is ", n);
        show(n);
    }

    return 0;
}
