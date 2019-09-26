#include <cstdio>
#include <cstring>

using namespace std;

int  n;
bool linked[100][100];
int  count[100];
int  ll[100000], lenl;
int  head, lenh;

void explore()
{
    int nhead = head + lenh;
    int nlenh = 0;

    for (int i = head; i < head + lenh; i += 2) {
        int x = ll[i], y = ll[i + 1];
        for (int j = 0; j < n; ++j)
            if (linked[y][j] && !linked[x][j]) {
                ll[nhead + nlenh++] = x;
                ll[nhead + nlenh++] = j;
                linked[x][j]        = true;
                count[x]--;
            }

        head = nhead;
        lenh = nlenh;
    }
}

int main(void)
{
    int m, s, d;

    while (1) {
        scanf("%d", &n);
        if (!n) break;

        lenl = 0;
        for (int i = 0; i < n; ++i) {
            memset(linked[i], false, sizeof(linked[i]));
            count[i] = n;
        }

        while (1) {
            scanf("%d", &s);
            if (!s) break;
            s--;

            while (1) {
                scanf("%d", &d);
                if (!d) break;
                d--;
                if (!linked[s][d]) {
                    ll[lenl++]   = s;
                    ll[lenl++]   = d;
                    linked[s][d] = true;
                    count[s]--;
                }
            }
        }

        head = 0;
        lenh = lenl;
        while (lenh)
            explore();

        scanf("%d", &m);
        while (m--) {
            scanf("%d", &s);
            s--;
            printf("%d", count[s]);
            for (int i = 0; i < n; ++i)
                if (!linked[s][i]) printf(" %d", i + 1);
            printf("\n");
        }
    }

    return 0;
}
