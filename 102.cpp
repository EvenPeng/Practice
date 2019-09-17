#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int    i, j, bin[9], max, total;
    int    count[6][4] = {{0, 2, 1, 0}, {0, 1, 2, 0}, {2, 0, 1, 0}, {2, 1, 0, 0}, {1, 0, 2, 0}, {1, 2, 0, 0}};
    string seq[6]      = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

    while (cin >> bin[0] >> bin[1] >> bin[2] >> bin[3] >> bin[4] >> bin[5] >> bin[6] >> bin[7] >> bin[8]) {
        total = 0;

        for (i = 0; i < 9; ++i)
            total += bin[i];

        for (i = 0; i < 6; ++i) {
            count[i][3] = 0;
            for (j = 0; j < 3; ++j)
                count[i][3] += bin[j * 3 + count[i][j]];
        }

        max = 0;
        for (i = 1; i < 6; ++i)
            if (count[i][3] > count[max][3]) max = i;

        total -= count[max][3];

        cout << seq[max] << " " << total << endl;
    }

    return 0;
}
