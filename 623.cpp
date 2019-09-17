#include <cstdio>
#include <iostream>

using namespace std;

#define UNIT 10000000000

int main(void)
{
    long digit[301];
    int  i, j, len, num;

    while (cin >> num) {
        cout << num << "!" << endl;

        len      = 1;
        digit[0] = 1;
        for (i = 1; i < 301; ++i)
            digit[i] = 0;

        for (j = 2; j <= num; ++j) {
            for (i = 0; i < len; ++i)
                digit[i] *= j;
            for (i = 0; i < len; ++i) {
                if (digit[i] >= UNIT) {
                    digit[i + 1] += digit[i] / UNIT;
                    digit[i] %= UNIT;
                    if (i == len - 1) len++;
                }
            }
        }

        printf("%ld", digit[len - 1]);
        for (i = len - 2; i >= 0; --i)
            printf("%010ld", digit[i]);
        printf("\n");
    }

    return 0;
}
