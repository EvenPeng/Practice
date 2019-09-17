#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int k, x, y, sum, cx, cy;

    while (true) {
        scanf("%d %d %d", &k, &x, &y);
        if (!k && !x && !y) break;
        sum = 0;
        cx  = 1024;
        cy  = 1024;

        while (k > 0) {
            if (x > cx) {
                if (y > cy) {
                    if (x - cx <= k && y - cy <= k) ++sum;
                    cx += k;
                    cy += k;
                }
                else {
                    if (x - cx <= k && cy - y <= k) ++sum;
                    cx += k;
                    cy -= k;
                }
            }
            else {
                if (y > cy) {
                    if (cx - x <= k && y - cy <= k) ++sum;
                    cx -= k;
                    cy += k;
                }
                else {
                    if (cx - x <= k && cy - y <= k) ++sum;
                    cx -= k;
                    cy -= k;
                }
            }
            k /= 2;
        }

        printf("%3d\n", sum);
    }

    return 0;
}
