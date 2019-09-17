#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int  count, tmp, index = 0;
    bool flag;

    cin >> count;

    for (int i = 0; i < count; ++i) {
        flag = true;
        for (int j = 0; j < 3; ++j) {
            cin >> tmp;
            if (tmp > 20) flag = false;
        }
        cout << "Case " << ++index << ": ";
        if (flag)
            cout << "good" << endl;
        else
            cout << "bad" << endl;
    }

    return 0;
}
