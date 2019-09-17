#include <cstdio>

using namespace std;

int table[8][8];
int moves[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};

void cnt(int x, int y)
{
    int i, tmpX, tmpY, sum;

    sum = table[x][y] + 1;
    for (i = 0; i < 8; ++i) {
        tmpX = x + moves[i][0];
        tmpY = y + moves[i][1];
        if (-1 < tmpX && tmpX < 8 && -1 < tmpY && tmpY < 8 && sum < table[tmpX][tmpY]) {
            table[tmpX][tmpY] = sum;
            cnt(tmpX, tmpY);
        }
    }
}

int main(void)
{
    int  i, j;
    char begX, begY, endX, endY;

    while (scanf("%c%c %c%c\n", &begX, &begY, &endX, &endY) != EOF) {
        for (i = 0; i < 8; ++i)
            for (j = 0; j < 8; ++j)
                table[i][j] = 64;

        table[begX - 'a'][begY - '1'] = 0;
        cnt((int)(begX - 'a'), (int)(begY - '1'));

        printf("To get from %c%c to %c%c takes %d knight moves.\n", begX, begY, endX, endY,
               table[endX - 'a'][endY - '1']);
    }

    return 0;
}
