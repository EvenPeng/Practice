#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char a[11], b[11], tmp;
    int  indexA, indexB, sum;
    bool flag;

    while (true) {
        scanf("%s %s", a, b);
        if (a[0] == '0' && b[0] == '0') break;

        indexA = 0;
        indexB = 0;
        while (a[indexA] != '\0')
            indexA++;
        while (b[indexB] != '\0')
            indexB++;

        sum = 0;
        indexA--;
        indexB--;
        flag = false;

        while (indexA > -1 && indexB > -1) {
            tmp = a[indexA--] + b[indexB--] - '0';
            if (flag) tmp++;
            if (tmp > '9') {
                sum++;
                flag = true;
                // cout << indexA << endl;
            }
            else
                flag = false;
        }

        while (indexA > -1 && flag) {
            if (a[indexA--] == '9')
                sum++;
            else
                flag = false;
        }

        while (indexB > -1 && flag) {
            if (b[indexB--] == '9')
                sum++;
            else
                flag = false;
        }

        if (sum == 0)
            cout << "No carry operation." << endl;
        else if (sum == 1)
            cout << "1 carry operation." << endl;
        else
            cout << sum << " carry operations." << endl;
    }

    return 0;
}
