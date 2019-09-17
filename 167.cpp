#include <cstdio>
#include <cstring>

using namespace std;

struct board {
    bool arr[8][8];
    int  score;
};

int   len;
board list[92], tmpS;
bool  check[46];

void gen(int x, int y)
{
    int i;

    check[x]          = false;
    check[8 + y]      = false;
    check[16 + x + y] = false;
    check[38 - x + y] = false;
    tmpS.arr[x][y]    = true;

    for (i = 0; i < 8; ++i)
        if (check[x + 1] && check[8 + i] && check[17 + x + i] && check[37 - x + i]) {
            if (x + 1 == 7) {
                memcpy(list + len, &tmpS, sizeof(board));
                list[len].arr[x + 1][i] = true;
                len++;
            }
            else
                gen(x + 1, i);
        }

    check[x]          = true;
    check[8 + y]      = true;
    check[16 + x + y] = true;
    check[38 - x + y] = true;
    tmpS.arr[x][y]    = false;
}

int main(void)
{
    int times, i, j, k, s, max;

    memset(check, true, sizeof(bool) * 46);
    memset(tmpS.arr, false, sizeof(bool) * 64);
    for (i = 0; i < 8; ++i)
        gen(0, i);

    scanf("%d", &times);

    while (times-- > 0) {
        max = 0;
        for (k = 0; k < len; ++k)
            list[k].score = 0;
        for (i = 0; i < 8; ++i)
            for (j = 0; j < 8; ++j) {
                scanf("%d", &s);
                for (k = 0; k < len; ++k)
                    if (list[k].arr[i][j]) {
                        list[k].score += s;
                        max = list[k].score > max ? list[k].score : max;
                    }
            }

        printf("%5d\n", max);
    }

    return 0;
}
