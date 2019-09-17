#include <iostream>
#include <stdlib.h>

using namespace std;

int a, b, Ax, Ay, Bx, By, len, block[25][25];

void search(void)
{
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j) {
            if (block[i][j] == -1) break;
            if (block[i][j] == a) {
                Ax = i;
                Ay = j;
            }
            if (block[i][j] == b) {
                Bx = i;
                By = j;
            }
        }
}

int main(int argc, char const *argv[])
{
    char word[5];
    int  tmp, tmp_b;

    cin >> len;

    for (int i = 0; i < len; ++i) {
        block[i][0] = i;
        for (int j = 1; j < len; ++j)
            block[i][j] = -1;
    }

    cin >> word;
    while (word[0] != 'q') {
        if (word[0] == 'm') {
            cin >> a >> word >> b;
            search();

            if (Ax == Bx) {
                cin >> word;
                continue;
            }

            tmp   = Ay + 1;
            tmp_b = block[Ax][tmp];
            while (tmp_b > -1) {
                block[tmp_b][0]  = tmp_b;
                block[Ax][tmp++] = -1;
                tmp_b            = block[Ax][tmp];
            }

            if (word[1] == 'n') { // move a onto b
                tmp   = By + 1;
                tmp_b = block[Bx][tmp];
                while (tmp_b > -1) {
                    block[tmp_b][0]  = tmp_b;
                    block[Bx][tmp++] = -1;
                    tmp_b            = block[Bx][tmp];
                }

                By++;
            }
            else { // move a over b
                while (block[Bx][By] > -1)
                    By++;
            }

            block[Ax][Ay] = -1;
            block[Bx][By] = a;
        }
        else {
            cin >> a >> word >> b;
            search();

            if (Ax == Bx) {
                cin >> word;
                continue;
            }

            if (word[1] == 'n') { // pile a onto b
                tmp   = By + 1;
                tmp_b = block[Bx][tmp];
                while (tmp_b > -1) {
                    block[tmp_b][0]  = tmp_b;
                    block[Bx][tmp++] = -1;
                    tmp_b            = block[Bx][tmp];
                }

                By++;
            }
            else { // pile a over b
                while (block[Bx][By] > -1)
                    By++;
            }

            tmp_b = block[Ax][Ay];
            while (tmp_b > -1) {
                block[Bx][By++] = tmp_b;
                block[Ax][Ay++] = -1;
                tmp_b           = block[Ax][Ay];
            }
        }

        cin >> word;
    }

    for (int i = 0; i < len; ++i) {
        cout << i << ":";
        for (int j = 0; j < len; ++j)
            if (block[i][j] > -1) cout << " " << block[i][j];
        cout << endl;
    }

    return 0;
}
