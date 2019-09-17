#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  count, sum;
    char tmp[6];

    cin >> count;

    for (int i = 0; i < count; ++i) {
        cin >> tmp;
        if (strlen(tmp) > 3)
            cout << 3 << endl;
        else {
            sum = 0;
            if (tmp[0] == 'o') sum++;
            if (tmp[1] == 'n') sum++;
            if (tmp[2] == 'e') sum++;
            if (sum >= 2)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
    }

    return 0;
}
