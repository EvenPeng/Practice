#include <cstdio>

using namespace std;

int main(void)
{
    int n, curr, total;

    while (scanf("%d", &n) != EOF) {
        total = n;
        curr  = n;
        while (curr >= 3) {
            total += curr / 3;
            curr = curr % 3 + curr / 3;
        }
        if (curr > 0) {
            total = n;
            curr += n;
            while (curr >= 3) {
                total += curr / 3;
                curr = curr % 3 + curr / 3;
            }
        }
        printf("%d\n", total);
    }

    return 0;
}
