#include <array>
#include <iostream>
#include <string>

int main(void)
{
    bool is_star;
    int  num_row, num_col, count;

    int move[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                      {0, 1},   {1, -1}, {1, 0},  {1, 1}};
    std::array<std::string, 100> sky;

    while (1) {
    std:;
        std::cin >> num_row >> num_col;
        if (!num_row && !num_col) break;

        for (int i = 0; i < num_row; ++i) {
            std::cin >> sky[i];
        }

        count = 0;
        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                if (sky[i][j] == '*') {
                    is_star = true;
                    for (int k = 0; is_star && k < 8; ++k) {
                        if (-1 < i + move[k][0] && i + move[k][0] < num_row &&
                            -1 < j + move[k][1] && j + move[k][1] < num_col)
                            is_star =
                                sky[i + move[k][0]][j + move[k][1]] == '.';
                    }
                    if (is_star) ++count;
                }
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
