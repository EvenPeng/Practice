#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>

struct Tile {
    int x, y, l;
};

int main(void)
{
    int size, max_step;

    Tile                                     curr;
    std::queue<Tile>                         q;
    std::array<std::string, 1000>            board;
    std::array<std::array<bool, 1000>, 1000> seen;

    while (std::cin >> size) {
        for (int i = 0; i < size; ++i) {
            std::cin >> board[i];
            seen[i].fill(false);
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == '3') {
                    q.push({i, j, 0});
                    seen[i][j] = true;
                }
            }
        }

        max_step = 0;
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            if (curr.x - 1 > -1 && !seen[curr.x - 1][curr.y]) {
                seen[curr.x - 1][curr.y] = true;
                if (board[curr.x - 1][curr.y] == '1')
                    max_step = std::max(max_step, curr.l + 1);
                q.push({curr.x - 1, curr.y, curr.l + 1});
            }
            if (curr.x + 1 < size && !seen[curr.x + 1][curr.y]) {
                seen[curr.x + 1][curr.y] = true;
                if (board[curr.x + 1][curr.y] == '1')
                    max_step = std::max(max_step, curr.l + 1);
                q.push({curr.x + 1, curr.y, curr.l + 1});
            }
            if (curr.y - 1 > -1 && !seen[curr.x][curr.y - 1]) {
                seen[curr.x][curr.y - 1] = true;
                if (board[curr.x][curr.y - 1] == '1')
                    max_step = std::max(max_step, curr.l + 1);
                q.push({curr.x, curr.y - 1, curr.l + 1});
            }
            if (curr.y + 1 < size && !seen[curr.x][curr.y + 1]) {
                seen[curr.x][curr.y + 1] = true;
                if (board[curr.x][curr.y + 1] == '1')
                    max_step = std::max(max_step, curr.l + 1);
                q.push({curr.x, curr.y + 1, curr.l + 1});
            }
        }

        std::cout << max_step << std::endl;
    }

    return 0;
}
