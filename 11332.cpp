#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, tmp;

    while (1) {
        cin >> num;
        if (num < 1) break;
        while (num > 9) {
            tmp = num;
            num = 0;
            while (tmp > 0) {
                num += tmp % 10;
                tmp /= 10;
            }
        }

        cout << num << endl;
    }

    return 0;
}
