#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int  num, count, cost[20], max, MAX, tmp, index = 1;
    bool table[20], flag;

    flag = false;

    while (1) {
        cin >> num >> count >> MAX;
        if (num == 0 && count == 0 && MAX == 0) break;

        max = 0;

        for (int i = 0; i < num; ++i) {
            cin >> cost[i];
            table[i] = false;
        }

        for (int i = 0; i < count; ++i) {
            cin >> tmp;
            tmp--;
            if (table[tmp])
                table[tmp] = false;
            else
                table[tmp] = true;

            tmp = 0;
            for (int j = 0; j < num; ++j)
                if (table[j]) tmp += cost[j];

            if (tmp > max) max = tmp;
        }

        if (max > MAX)
            cout << "Sequence " << index++ << endl << "Fuse was blown." << endl;
        else
            cout << "Sequence " << index++ << endl
                 << "Fuse was not blown." << endl
                 << "Maximal power consumption was " << max << " amperes." << endl;
        cout << endl;
    }

    return 0;
}
