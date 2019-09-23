#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

bool check[101][101];
int  pp[20000], blockI[20000], blockII[20000], lenp, lenl, n, *ll;

void explore()
{
    int *ss   = ll == blockII ? blockI : blockII;
    int  lens = 0;

    for (int i = 0; i < lenl; i += 2) {
        int a = ll[i], b = ll[i + 1];
        for (int j = 0; j < lenp; j += 2) {
            int c = pp[j], d = pp[j + 1];
            if (!check[a][d] && b == c) {
                ss[lens++]  = a;
                ss[lens++]  = d;
                check[a][d] = true;
            }
        }
    }

    ll   = ss;
    lenl = lens;
}

int main(void)
{
    bool first;
    int  T, x, y, sum, cnt;

    first = true;
    for (int i = 0; i < 101; ++i) {
        memset(check[i], false, sizeof(check[i]));
        check[i][i] = true;
    }
    T    = 0;
    lenp = 0;
    while (1) {
        scanf("%d %d", &x, &y);
        if (!x && !y) {
            if (first) break;

            ll   = blockI;
            lenl = lenp;
            memcpy(ll, pp, sizeof(pp));

            sum = lenl / 2;
            cnt = sum;
            for (int k = 2; lenl > 0; ++k) {
                explore();
                sum += (lenl / 2) * k;
                cnt += lenl / 2;
            }

            printf("Case %d: average length between pages = %.3lf clicks\n", ++T, (double)sum / cnt);

            lenp  = 0;
            first = true;
            for (int i = 0; i < 101; ++i) {
                memset(check[i], false, sizeof(check[i]));
                check[i][i] = true;
            }
        }
        else {
            if (!check[x][y]) {
                pp[lenp++]  = x;
                pp[lenp++]  = y;
                check[x][y] = true;
            }
            first = false;
        }
    }

    return 0;
}
