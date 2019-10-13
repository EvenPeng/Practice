#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

struct Post {
    int x, y;
} posts[500];

int  s, p, md[500], con[500];
int  dist[500][500];
bool seen[500];

int Cal(int i, int j)
{
    int dx = posts[i].x - posts[j].x;
    int dy = posts[i].y - posts[j].y;
    return dx * dx + dy * dy;
}

int main(void)
{
    int T;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &s, &p);
        for (int i = 0; i < p; ++i) {
            scanf("%d %d", &posts[i].x, &posts[i].y);
            for (int j = 0; j < i; ++j) {
                dist[i][j] = Cal(i, j);
                dist[j][i] = dist[i][j];
            }
            dist[i][i] = 0;
        }

        memcpy(md, dist[0], sizeof(md));
        memset(seen, false, sizeof(seen));
        seen[0] = true;
        for (int i = 0; i < p - 1; ++i) {
            int j = 1;
            while (seen[j])
                ++j;
            for (int k = j + 1; k < p; ++k)
                if (!seen[k] && md[k] < md[j]) {
                    j = k;
                }
            con[i]  = md[j];
            seen[j] = true;
            for (int k = 0; k < p; ++k)
                if (!seen[k]) md[k] = min(md[k], dist[j][k]);
        }

        sort(con, con + p - 1);
        printf("%.2lf\n", sqrt(con[p - s - 1]));
    }

    return 0;
}
