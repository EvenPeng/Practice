#include <cstdio>
#include <cstring>

using namespace std;

inline int cmp(int l, int m, int L, int M)
{
    if (m == M) {
        if (l == L)
            return 0;
        else if (l % 2) {
            if (L % 2)
                return L > l ? 1 : -1;
            else
                return -1;
        }
        else {
            if (L % 2)
                return 1;
            else
                return l > L ? 1 : -1;
        }
    }
    else
        return m - M;
}

void sortA(int *list, int *mod, int len)
{
    int i      = 0;
    int j      = len - 1;
    int pivotL = list[len / 2];
    int pivotM = mod[len / 2];
    int tmpI;

    if (len < 2) return;

    while (true) {
        while (cmp(list[i], mod[i], pivotL, pivotM) < 0)
            ++i;
        while (cmp(list[j], mod[j], pivotL, pivotM) > 0)
            --j;
        if (i >= j) break;
        tmpI     = list[i];
        list[i]  = list[j];
        list[j]  = tmpI;
        tmpI     = mod[i];
        mod[i++] = mod[j];
        mod[j--] = tmpI;
    }

    sortA(list, mod, i);
    sortA(list + i, mod + i, len - i);
}

int main(void)
{
    int n, m, i;
    int list[10000], mod[10000];

    while (true) {
        scanf("%d %d", &n, &m);
        if (!n && !m) {
            printf("0 0\n");
            break;
        }

        for (i = 0; i < n; ++i) {
            scanf("%d", list + i);
            mod[i] = list[i] % m;
        }

        sortA(list, mod, n);

        printf("%d %d\n", n, m);
        for (i = 0; i < n; ++i)
            printf("%d\n", list[i]);
    }

    return 0;
}
