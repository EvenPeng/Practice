#include <cstdio>

using namespace std;

struct node {
    int label, l, r;
};

node list[21];

static inline void remove(int index)
{
    list[list[index].r].l = list[index].l;
    list[list[index].l].r = list[index].r;
}

int main(void)
{
    int N, k, m, i, iR, iL;

    while (true) {
        scanf("%d %d %d", &N, &k, &m);
        if (N < 1) break;

        for (i = 0; i < N; ++i) {
            list[i].label = i + 1;
            list[i].l     = (i + N - 1) % N;
            list[i].r     = (i + 1) % N;
        }

        iR = 0;
        iL = N - 1;

        k--;
        m--;

        while (true) {
            for (i = 0; i < k % N; ++i)
                iR = list[iR].r;
            for (i = 0; i < m % N; ++i)
                iL = list[iL].l;

            if (iR != iL) {
                printf("%3d%3d", list[iR].label, list[iL].label);
                if (iR == list[iL].l) {
                    remove(iR);
                    remove(iL);
                    iR = list[iL].r;
                    iL = list[iR].l;
                }
                else {
                    remove(iR);
                    remove(iL);
                    iR = list[iR].r;
                    iL = list[iL].l;
                }
                N -= 2;
            }
            else {
                printf("%3d", list[iR].label);
                remove(iR);
                iR = list[iR].r;
                iL = list[iL].l;
                N--;
            }

            if (N > 0)
                printf(",");
            else
                break;
        }
        printf("\n");
    }

    return 0;
}
