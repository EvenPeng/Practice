#include <cmath>
#include <cstdio>

using namespace std;

int main(void)
{
    int root, row, col, n;

    while (scanf("%d", &n) != EOF && n > 0) {
        root = (int)ceil(sqrt((double)n));
        n    = (int)pow((double)root, 2) - n;
        if (root % 2) {
            row = 1;
            col = root;
            if (n > root - 1) {
                row += root - 1;
                n -= root - 1;
            }
            else {
                row += n;
                n = 0;
            }
            if (n > root - 1) {
                col -= root - 1;
                n -= root - 1;
            }
            else {
                col -= n;
                n = 0;
            }
        }
        else {
            row = root;
            col = 1;
            if (n > root - 1) {
                col += root - 1;
                n -= root - 1;
            }
            else {
                col += n;
                n = 0;
            }
            if (n > root - 1) {
                row -= root - 1;
                n -= root - 1;
            }
            else {
                row -= n;
                n = 0;
            }
        }
        printf("%d %d\n", row, col);
    }

    return 0;
}
