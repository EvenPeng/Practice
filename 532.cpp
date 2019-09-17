#include <cstdio>
#include <cstring>

using namespace std;

char map[32][32][32];
int  cnt[32][32][32];
int  dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

struct cell {
    int Cx, Cy, Cz;
};

cell queue[1000];
int  rear, lenQ;

int main(void)
{
    int  l, r, c, i, j, k;
    int  Sx, Sy, Sz, Ex, Ey, Ez, nCnt;
    cell tmpS;

    while (true) {
        scanf("%d %d %d", &l, &r, &c);
        if (l < 1) break;
        memset(map, '#', sizeof(char) * 32 * 32 * 32);
        memset(cnt, 0, sizeof(int) * 32 * 32 * 32);

        for (i = 1; i <= l; ++i)
            for (j = 1; j <= r; ++j) {
                scanf("%s", &map[i][j][1]);
                map[i][j][c + 1] = '#';
            }

        for (i = 1; i <= l; ++i)
            for (j = 1; j <= r; ++j)
                for (k = 1; k <= c; ++k) {
                    if (map[i][j][k] == 'S') {
                        Sx = i;
                        Sy = j;
                        Sz = k;
                    }
                    if (map[i][j][k] == 'E') {
                        Ex = i;
                        Ey = j;
                        Ez = k;
                    }
                }

        rear        = 0;
        lenQ        = 1;
        queue[0].Cx = Sx;
        queue[0].Cy = Sy;
        queue[0].Cz = Sz;

        while (lenQ > 0) {
            nCnt = cnt[queue[rear].Cx][queue[rear].Cy][queue[rear].Cz] + 1;
            for (i = 0; i < 6; ++i) {
                tmpS.Cx = queue[rear].Cx + dir[i][0];
                tmpS.Cy = queue[rear].Cy + dir[i][1];
                tmpS.Cz = queue[rear].Cz + dir[i][2];
                if (map[tmpS.Cx][tmpS.Cy][tmpS.Cz] != '#') {
                    if (cnt[tmpS.Cx][tmpS.Cy][tmpS.Cz] == 0 || cnt[tmpS.Cx][tmpS.Cy][tmpS.Cz] > nCnt) {
                        cnt[tmpS.Cx][tmpS.Cy][tmpS.Cz] = nCnt;
                        memcpy(&queue[(rear + lenQ) % 1000], &tmpS, sizeof(cell));
                        lenQ++;
                    }
                }
            }

            rear = (rear + 1) % 1000;
            lenQ--;
        }

        if (cnt[Ex][Ey][Ez] > 0)
            printf("Escaped in %d minute(s).\n", cnt[Ex][Ey][Ez]);
        else
            printf("Trapped!\n");
    }

    return 0;
}
