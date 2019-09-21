#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int T, n, src, dst, c, x, y, b, result;

bool seen[100];
int  mm[100][100];

int travel(int s, int cap)
{
    if (s == dst) return cap;

    seen[s] = true;
    for (int i = 0; i < n; i++)
        if (!seen[i] && mm[s][i] > 0) {
            int tmp = travel(i, min(cap, mm[s][i]));
            if (tmp > 0) {
                mm[s][i] -= tmp;
                mm[i][s] += tmp;
                return tmp;
            }
        }

    return 0;
}

int main(void)
{
    T = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; ++i)
            memset(mm[i], 0, sizeof(mm[i]));

        scanf("%d %d %d", &src, &dst, &c);
        src--;
        dst--;

        for (int i = 0; i < c; ++i) {
            scanf("%d %d %d", &x, &y, &b);
            x--;
            y--;
            mm[x][y] += b;
            mm[y][x] += b;
        }

        result = 0;
        while (1) {
            memset(seen, false, sizeof(seen));
            b = travel(src, 100001);
            if (b == 0) break;
            result += b;
        }

        printf("Network %d\n", ++T);
        printf("The bandwidth is %d.\n\n", result);
    }

    return 0;
}
