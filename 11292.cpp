#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
    int n, m, i, j, lenD, lenK, dragon[20000], knight[20000], sum;

    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        lenD = n;
        lenK = m;
        for (i = 0; i < n; ++i)
            scanf("%d", dragon + i);
        for (i = 0; i < m; ++i)
            scanf("%d", knight + i);

        if (m >= n) {
            sort(dragon, dragon + n);
            sort(knight, knight + m);
        }
        else {
            printf("Loowater is doomed!\n");
            continue;
        }

        sum = 0;
        i   = 0;
        j   = 0;
        if (knight[m - 1] >= dragon[n - 1] && knight[m - n] >= dragon[0])
            while (lenK >= lenD) {
                if (knight[i] >= dragon[j]) {
                    sum += knight[i];
                    j++;
                    lenD--;
                    if (!lenD) break;
                }
                i++;
                lenK--;
            }

        if (lenD > 0)
            printf("Loowater is doomed!\n");
        else
            printf("%d\n", sum);
    }

    return 0;
}
