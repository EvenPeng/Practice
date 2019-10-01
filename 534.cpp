#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

struct Stone {
    double x, y;
} stones[200];

struct Jump {
    int    dst;
    double dis;
} jumps[200][200];
int lenj[200];

bool compareJumps(const Jump &x, const Jump &y) { return x.dis < y.dis; }

int    n;
bool   seen[200];
double dis[200];

inline double cal(Stone *A, Stone *B) { return sqrt(pow(A->x - B->x, 2) + pow(A->y - B->y, 2)); }

int main(void)
{
    int T;

    T = 0;
    while (1) {
        scanf("%d", &n);
        if (!n) break;

        scanf("%lf %lf", &stones[0].x, &stones[0].y);
        scanf("%lf %lf", &stones[n - 1].x, &stones[n - 1].y);

        for (int i = 1; i < n - 1; ++i)
            scanf("%lf %lf", &stones[i].x, &stones[i].y);

        memset(lenj, 0, sizeof(lenj));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                jumps[i][lenj[i]].dst = j;
                jumps[i][lenj[i]].dis = cal(stones + i, stones + j);
                jumps[j][lenj[j]].dst = i;
                jumps[j][lenj[j]].dis = jumps[i][lenj[i]].dis;
                lenj[i]++;
                lenj[j]++;
            }

        for (int i = 0; i < n; ++i)
            sort(jumps[i], jumps[i] + lenj[i], compareJumps);

        memset(seen, false, sizeof(seen));
        for (int i = 0; i < lenj[0]; ++i)
            dis[jumps[0][i].dst] = jumps[0][i].dis;
        int id = jumps[0][0].dst;
        while (id < n - 1) {
            seen[id] = true;
            for (int i = 0; i < lenj[id]; ++i)
                dis[jumps[id][i].dst] = min(dis[jumps[id][i].dst], max(jumps[id][i].dis, dis[id]));
            id = 1;
            while (seen[id])
                id++;
            for (int i = id + 1; i < n; ++i)
                if (!seen[i] && dis[i] < dis[id]) id = i;
        }

        printf("Scenario #%d\n", ++T);
        printf("Frog Distance = %.3lf\n\n", dis[n - 1]);
    }

    return 0;
}
