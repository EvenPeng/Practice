#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int    count, max, pro[10];
    string st[10];

    cin >> count;

    for (int i = 0; i < count; ++i) {
        max = 0;
        for (int j = 0; j < 10; ++j) {
            cin >> st[j] >> pro[j];
            if (pro[j] > max) max = pro[j];
        }

        cout << "Case #" << i + 1 << ":" << endl;
        for (int j = 0; j < 10; ++j) {
            if (pro[j] == max) cout << st[j] << endl;
        }
    }

    return 0;
}
