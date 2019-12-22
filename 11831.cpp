#include <array>
#include <iostream>
#include <string>

struct Move {
    int x, y;
};

int main(void)
{
    int                          num_row, num_col, num_op;
    int                          x, y, d, nx, ny, count;
    std::string                  ops;
    std::array<Move, 4>          move = {Move{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    std::array<std::string, 100> board;

    while (1) {
        std::cin >> num_row >> num_col >> num_op;
        if (!num_row && !num_col && !num_op) break;

        x = -1;
        for (int i = 0; i < num_row; ++i) {
            std::cin >> board[i];
            for (int j = 0; x == -1 && j < board[i].size(); ++j) {
                if (board[i][j] == 'N') {
                    x = i;
                    y = j;
                    d = 0;
                }
                else if (board[i][j] == 'S') {
                    x = i;
                    y = j;
                    d = 2;
                }
                else if (board[i][j] == 'L') {
                    x = i;
                    y = j;
                    d = 1;
                }
                else if (board[i][j] == 'O') {
                    x = i;
                    y = j;
                    d = 3;
                }
            }
        }

        count = 0;
        std::cin >> ops;
        for (auto const &m : ops) {
            if (m == 'D')
                d = (d + 1) % 4;
            else if (m == 'E')
                d = (d + 3) % 4;
            else {
                nx = x + move[d].x;
                ny = y + move[d].y;
                if (0 <= nx && nx < num_row && 0 <= ny && ny < num_col) {
                    if (board[nx][ny] != '#') {
                        x = nx;
                        y = ny;
                        if (board[x][y] == '*') {
                            board[x][y] = '.';
                            ++count;
                        }
                    }
                }
            }
        }
        std::cout << count << std::endl;
    }

    return 0;
}
