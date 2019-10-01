#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Chess {
    char type;
    int  x, y;
} wc[64], bc[64], wk, bk;
int  lenw, lenb;
bool exist[8][8];

inline void parse(int x, int y, char c)
{
    exist[x][y] = true;
    switch (c) {
    case 'K':
        wk.x = x;
        wk.y = y;
    case 'P':
    case 'N':
    case 'B':
    case 'R':
    case 'Q':
        wc[lenw].x      = x;
        wc[lenw].y      = y;
        wc[lenw++].type = c;
        break;
    case 'k':
        bk.x = x;
        bk.y = y;
    case 'p':
    case 'n':
    case 'b':
    case 'r':
    case 'q':
        bc[lenb].x      = x;
        bc[lenb].y      = y;
        bc[lenb++].type = c;
        break;
    }
}

bool checkDiagonal(int cx, int cy, int kx, int ky)
{
    if ((abs(cx - kx) == abs(cy - ky))) {
        if (cx > kx) {
            if (cy > ky) {
                for (int i = cx - 1, j = cy - 1; i > kx && j > ky; --i, --j)
                    if (exist[i][j]) return false;
            }
            else {
                for (int i = cx - 1, j = cy + 1; i > kx && j < ky; --i, ++j)
                    if (exist[i][j]) return false;
            }
        }
        else {
            if (cy > ky) {
                for (int i = cx + 1, j = cy - 1; i < kx && j > ky; ++i, --j)
                    if (exist[i][j]) return false;
            }
            else {
                for (int i = cx + 1, j = cy + 1; i < kx && j < ky; ++i, ++j)
                    if (exist[i][j]) return false;
            }
        }
        return true;
    }
    return false;
}

bool checkCross(int cx, int cy, int kx, int ky)
{
    if (cx == kx) {
        if (cy < ky) swap(cy, ky);
        for (int i = ky + 1; i < cy; ++i)
            if (exist[cx][i]) return false;
        return true;
    }
    if (cy == ky) {
        if (cx < kx) swap(cx, kx);
        for (int i = kx + 1; i < cx; ++i)
            if (exist[i][cy]) return false;
        return true;
    }
    return false;
}

bool check(Chess *c, Chess *k)
{
    int cx = c->x;
    int cy = c->y;
    int kx = k->x;
    int ky = k->y;

    switch (c->type) {
    case 'P':
        return (cx - 1 == kx && abs(cy - ky) == 1);
    case 'p':
        return (cx + 1 == kx && abs(cy - ky) == 1);
    case 'N':
    case 'n':
        return (abs(cx - kx) == 2 && abs(cy - ky) == 1) || (abs(cx - kx) == 1 && abs(cy - ky) == 2);
    case 'Q':
    case 'q':
        return checkDiagonal(cx, cy, kx, ky) || checkCross(cx, cy, kx, ky);
    case 'B':
    case 'b':
        return checkDiagonal(cx, cy, kx, ky);
    case 'R':
    case 'r':
        return checkCross(cx, cy, kx, ky);
    }
    return false;
}

int main(void)
{
    bool checkw, checkb;
    char line[10];
    int  T = 0;

    lenw = lenb = 0;
    memset(exist, false, sizeof(exist));
    while (1) {
        for (int i = 0; i < 8; ++i) {
            scanf("%s", line);
            for (int j = 0; j < 8; ++j)
                if (line[j] != '.') parse(i, j, line[j]);
        }
        if (!lenw && !lenb) break;

        checkb = false;
        checkw = false;
        for (int i = 0; !checkw && !checkb && i < lenb; ++i)
            checkw = check(bc + i, &wk);
        for (int i = 0; !checkw && !checkb && i < lenw; ++i)
            checkb = check(wc + i, &bk);

        if (checkw)
            printf("Game #%d: white king is in check.\n", ++T);
        else if (checkb)
            printf("Game #%d: black king is in check.\n", ++T);
        else
            printf("Game #%d: no king is in check.\n", ++T);

        lenw = lenb = 0;
        memset(exist, false, sizeof(exist));
    }

    return 0;
}
