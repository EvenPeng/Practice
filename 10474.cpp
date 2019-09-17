#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
    int index, n, q, i, j, M[100000], Q[100000];

    index = 0;
    while (true) {
        scanf("%d %d", &n, &q);
        if (n == 0 && q == 0) break;
        for (i = 0; i < n; ++i)
            scanf("%d", M + i);
        for (j = 0; j < q; ++j)
            scanf("%d", Q + j);
        sort(M, M + n);

        printf("CASE# %d:\n", ++index);
        for (j = 0; j < q; ++j) {
            for (i = 0; i < n; ++i)
                if (M[i] == Q[j] || M[i] > Q[j]) break;
            if (i < n && M[i] == Q[j])
                printf("%d found at %d\n", Q[j], i + 1);
            else
                printf("%d not found\n", Q[j]);
        }
    }

    return 0;
}
