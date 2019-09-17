#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int  iter, tmp_iter, arr_1[21], arr_2[21], index, *pre, *curr, *tmp, carry;
    long base;
    bool flag;

    curr = arr_1;
    pre  = arr_2;

    cin >> iter;

    while (iter-- > 0) {
        cin >> base;
        index = 0;
        while (base > 0) {
            pre[index++] = (int)(base % 10);
            base /= 10;
        }

        tmp_iter = 0;

        while (true) {
            flag = true;
            for (int i = 0; i < index / 2; ++i)
                if (pre[i] != pre[index - i - 1]) {
                    flag = false;
                    break;
                }
            if (flag) break;

            tmp_iter++;
            carry = 0;
            for (int j = 0; j < index; ++j) {
                curr[j] = pre[j] + pre[index - j - 1] + carry;
                if (curr[j] >= 10) {
                    curr[j] -= 10;
                    carry = 1;
                }
                else
                    carry = 0;
            }
            if (carry > 0) curr[index++] = 1;

            tmp  = curr;
            curr = pre;
            pre  = tmp;
        }

        cout << tmp_iter << " ";
        for (int i = 0; i < index; ++i)
            cout << pre[i];
        cout << endl;
    }

    return 0;
}
