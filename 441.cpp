#include <cstdio>

using namespace std;

int nBits(unsigned int u)
{
    unsigned int uCount;

    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    uCount = ((uCount + (uCount >> 3)) & 030707070707) % 63;

    return (int)uCount;
}

int main(void)
{
    bool flag;
    int  len, list[13], n, i;

    flag = false;

    while (true) {
        scanf("%d", &len);
        if (len < 1) break;
        if (flag)
            printf("\n");
        else
            flag = true;

        for (i = len - 1; i > -1; --i)
            scanf("%d", list + i);
        n = ((1 << 6) - 1) << (len - 6);
        do {
            if (nBits(n) != 6) continue;
            i = len - 1;
            while ((n & (1 << i)) == 0)
                --i;
            printf("%d", list[i]);
            while (--i > -1)
                if (n & (1 << i)) printf(" %d", list[i]);
            printf("\n");
        } while (n-- > 63);
    }

    return 0;
}
