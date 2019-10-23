#include <cstring>
#include <iostream>
#include <string>

std::string board[200];
int         num_rows;
bool        seen[200][200];

bool traversal(int x, int y)
{
    seen[x][y] = true;
    if (y == num_rows - 1) return true;

    if (x - 1 > -1) {
        if (y - 1 > -1 && !seen[x - 1][y - 1] && board[x - 1][y - 1] == 'w' &&
            traversal(x - 1, y - 1)) {
            return true;
        }
        if (!seen[x - 1][y] && board[x - 1][y] == 'w' && traversal(x - 1, y)) {
            return true;
        }
    }

    if (y - 1 > -1 && !seen[x][y - 1] && board[x][y - 1] == 'w' &&
        traversal(x, y - 1)) {
        return true;
    }
    if (y + 1 < num_rows && !seen[x][y + 1] && board[x][y + 1] == 'w' &&
        traversal(x, y + 1)) {
        return true;
    }

    if (x + 1 < num_rows) {
        if (!seen[x + 1][y] && board[x + 1][y] == 'w' && traversal(x + 1, y)) {
            return true;
        }
        if (y + 1 < num_rows && !seen[x + 1][y + 1] &&
            board[x + 1][y + 1] == 'w' && traversal(x + 1, y + 1)) {
            return true;
        }
    }

    return false;
}

int main(void)
{
    int  num_cases = 0;
    bool reachable;
    while (1) {
        std::cin >> num_rows;
        if (!num_rows) break;

        for (int i = 0; i < num_rows; ++i) {
            std::cin >> board[i];
            memset(seen[i], false, sizeof(seen[i]));
        }

        reachable = false;
        for (int i = 0; !reachable && i < num_rows; ++i)
            if (board[i][0] == 'w') {
                reachable = traversal(i, 0);
            }

        std::cout << ++num_cases << (reachable ? " W" : " B") << std::endl;
    }

    return 0;
}
