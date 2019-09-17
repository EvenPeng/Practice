#include <cmath>
#include <iostream>

using namespace std;

void sortS(int *arr, int len)
{
    int i = 0, j = len - 1, tmpInt;
    int pivot = arr[len / 2];

    if (len < 2) return;

    while (true) {
        while (arr[i] < pivot)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i >= j) break;
        tmpInt   = arr[i];
        arr[i++] = arr[j];
        arr[j--] = tmpInt;
    }

    sortS(arr, i);
    sortS(arr + i, len - i);
}

int main(void)
{
    int times, ALen, arr[30001], i, sum;

    cin >> times;

    while (times-- > 0) {
        cin >> ALen;
        for (i = 0; i < ALen; ++i)
            cin >> arr[i];
        sortS(arr, ALen);
        sum = 0;
        for (i = 0; i < ALen; ++i) {
            sum += abs(arr[i] - arr[ALen / 2]);
        }
        cout << sum << endl;
    }

    return 0;
}
