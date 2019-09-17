#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int  num, count, money[20], debet, credit, tmp;
    bool flag;

    while (1) {
        cin >> num >> count;
        if (num < 1) break;

        flag = true;

        for (int i = 0; i < num; ++i) {
            cin >> money[i];
        }

        for (int i = 0; i < count; ++i) {
            cin >> debet >> credit >> tmp;
            money[debet - 1] -= tmp;
            money[credit - 1] += tmp;
        }

        for (int i = 0; i < num; ++i) {
            if (money[i] < 0) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}
