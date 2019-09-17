#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define BASE 1000000000

long long power[64][2], fun[64][2];

void add(long long *a, long long *b, long long *c)
{
    c[1] = a[1] + b[1];
    c[0] = a[0] + b[0] + c[1] / BASE;
    c[1] %= BASE;
}

void miu(long long *a, long long *b, long long *c)
{
    c[1] = a[1] - b[1];
    c[0] = a[0] - b[0];
    while (c[1] < 0 && c[0] > 0) {
        c[1] += BASE;
        c[0]--;
    }
}

void seq(long long *num, long long *sum)
{
    if (num[0] == 0 && num[1] < 3)
        return;
    else if (num[0] == 0 && num[1] < 4) {
        sum[1]++;
        sum[0] += sum[1] / BASE;
        sum[1] %= BASE;
        return;
    }

    int       index;
    long long diff[2];
    for (index = 0; index < 64; ++index)
        if (power[index][0] > num[0] || (power[index][0] == num[0] && power[index][1] > num[1])) break;
    index--;

    add(fun[index], sum, sum);
    miu(num, power[index], diff);
    seq(diff, sum);
    diff[1]++;
    diff[0] += diff[1] / BASE;
    diff[1] %= BASE;
    if (diff[0] > power[index - 1][0] || (diff[0] == power[index - 1][0] && diff[1] >= power[index - 1][1])) {
        add(diff, sum, sum);
        miu(sum, power[index - 1], sum);
    }
}

int main(int argc, char const *argv[])
{
    long long num[2], index = 1, result[2];

    for (int i = 2; i < 64; ++i) {
        power[i][0] = 0;
        power[i][1] = 0;
        fun[i][0]   = 0;
        fun[i][1]   = 0;
    }

    power[0][1] = 1;
    power[1][1] = 2;

    for (int i = 2; i < 64; ++i) {
        add(power[i - 1], power[i - 1], power[i]);
        add(fun[i - 1], fun[i - 1], fun[i]);
        add(power[i - 2], fun[i], fun[i]);
    }

    while (true) {
        cin >> num[1];
        if (num[1] < 0) break;
        num[0] = num[1] / BASE;
        num[1] %= BASE;

        result[0] = 0;
        result[1] = 0;

        seq(num, result);

        if (result[0] < 1)
            cout << "Case " << index++ << ": " << result[1] << endl;
        else {
            cout << "Case " << index++ << ": " << result[0];
            printf("%09lld\n", result[1]);
        }
    }

    return 0;
}
