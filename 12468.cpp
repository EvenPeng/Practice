#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  head, tail, num;
    bool flag = false;

    while (1) {
        cin >> head >> tail;
        if (head < 0) break;
        if (flag) cout << endl;
        num = abs(head - tail);
        if (num > 50)
            cout << 100 - num << endl;
        else
            cout << num << endl;
    }

    return 0;
}
