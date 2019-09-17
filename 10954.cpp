#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    long sum, len, i, num[5001], min1, min2;

    while (cin >> len && len > 0) {
        for (i = 0; i < len; ++i)
            cin >> num[i];

        sum = 0;

        while (len > 1) {
            min1 = 0;
            min2 = 1;
            for (i = 1; i < len; ++i) {
                if (num[i] < num[min1]) {
                    min2 = min1;
                    min1 = i;
                }
                else if (num[i] < num[min2]) {
                    min2 = i;
                }
            }

            if (min1 > min2) {
                i    = min1;
                min1 = min2;
                min2 = i;
            }

            num[min1] += num[min2];
            num[min2] = num[--len];
            sum += num[min1];
        }

        cout << sum << endl;
    }

    return 0;
}
