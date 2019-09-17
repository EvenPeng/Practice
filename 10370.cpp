#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    double times, N, arr[1000], sum, cnt;

    cin >> times;

    for (int ii = 0; ii < times; ++ii) {
        cin >> N;
        sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        sum /= N;
        cnt = 0;
        for (int i = 0; i < N; ++i)
            if (arr[i] > sum) cnt++;
        printf("%.3f%%\n", cnt / N * 100);
    }

    return 0;
}
