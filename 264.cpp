#include <iostream>

using namespace std;

int main(void)
{
    int i, index;
    int base[4474], len;
    int up, down, begin, end, middle;

    len     = 4474;
    base[0] = 0;
    base[1] = 1;

    for (i = 1; i < len - 1; ++i)
        base[i + 1] = base[i] + i;

    while (cin >> index) {
        // binary search
        begin = 0;
        end   = len;

        while (end - begin > 1) {
            middle = (begin + end) / 2;
            if (index < base[middle])
                end = middle;
            else if (index > base[middle])
                begin = middle;
            else
                break;
        }

        middle = (begin + end) / 2;
        index -= base[middle];

        if (middle % 2) { // even
            up   = middle - index;
            down = 1 + index;
        }
        else { // odd
            up   = 1 + index;
            down = middle - index;
        }

        cout << "TERM " << (base[middle] + index) << " IS " << up << "/" << down << endl;
    }

    return 0;
}
