#include <iostream>

using namespace std;

int main(void)
{
    int arr[1001], len;
    int i, j, flips;

    cin >> len;
    while (cin >> len) {
        flips = 0;

        for (i = 0; i < len; ++i) {
            cin >> arr[i];
            for (j = 0; j < i; ++j)
                if (arr[j] > arr[i]) flips++;
        }

        cout << "Optimal train swapping takes " << flips << " swaps." << endl;
    }

    return 0;
}
