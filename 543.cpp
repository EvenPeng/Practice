#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int  num, prime[78498], pLen = 78497;
    bool check[1000001];
    prime[0] = 2;

    // bulid prime number table
    for (int i = 0; i < 1000001; ++i)
        check[i] = true;

    check[0] = false;
    check[1] = false;

    int index = 2;
    while (index < 1000) {
        for (int i = 2 * index; i < 1000001; i += index)
            check[i] = false;
        index++;

        while (!check[index])
            index++;
    }

    index = 0;
    for (int i = 0; i < 1000001; ++i)
        if (check[i]) prime[index++] = i;

    while (true) {
        cin >> num;
        if (num == 0) break;

        int indexL, indexR;

        indexL = 0;
        indexR = pLen / 2;

        for (int i = pLen / 4; i > 0; i /= 2) {
            if (prime[indexR] < num)
                indexR += i;
            else if (prime[indexR] > num)
                indexR -= i;
            else
                break;
        }

        while (indexR < pLen && prime[indexR] < num)
            indexR++;
        // cout << indexR << endl;

        while (true) {
            if (indexL > indexR) {
                cout << "Goldbach's conjecture is wrong." << endl;
                break;
            }

            int sum = prime[indexR] + prime[indexL];

            if (sum > num)
                indexR--;
            else if (sum < num)
                indexL++;
            else {
                cout << num << " = " << prime[indexL] << " + " << prime[indexR] << endl;
                break;
            }
        }
    }

    return 0;
}
