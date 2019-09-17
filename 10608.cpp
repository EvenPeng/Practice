#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int times, n, m, lenL, x, y, i, j, cnt[30001], label[30001];

    scanf("%d", &times);

    while (times-- > 0) {
        scanf("%d %d", &n, &m);
        memset(cnt + 1, 0, sizeof(int) * n);
        memset(label + 1, 0, sizeof(int) * n);
        lenL = 1;

        for (i = 1; i <= m; ++i) {
            scanf("%d %d", &x, &y);
            if (label[x] < 1) {
                if (label[y] < 1) {
                    label[x] = lenL;
                    label[y] = lenL;
                    cnt[lenL++] += x != y ? 2 : 1;
                }
                else {
                    label[x] = label[y];
                    cnt[label[y]]++;
                }
            }
            else {
                if (label[y] < 1) {
                    label[y] = label[x];
                    cnt[label[x]]++;
                }
                else if (label[x] < label[y]) {
                    y = label[y];
                    for (j = 1; j <= n; ++j)
                        if (label[j] == y) label[j] = label[x];
                    cnt[label[x]] += cnt[y];
                }
                else if (label[x] > label[y]) {
                    x = label[x];
                    for (j = 1; j <= n; ++j)
                        if (label[j] == x) label[j] = label[y];
                    cnt[label[y]] += cnt[x];
                }
            }
        }

        m = 0;
        for (i = 1; i <= lenL; ++i)
            m = cnt[i] > m ? cnt[i] : m;
        printf("%d\n", m);
    }

    return 0;
}
