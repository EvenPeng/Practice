#include <array>
#include <iostream>
#include <string>

int main(void)
{
    int num_row, num_col, x, y, s, last;

    std::array<std::string, 1000>           board;
    std::array<std::array<int, 1000>, 1000> count;

    while (1) {
        std::cin >> num_row >> num_col >> y;
        if (!num_row && !num_col && !y) break;

        for (int i = 0; i < num_row; ++i) {
            std::cin >> board[i];
            count[i].fill(0);
        }

        x = 0;
        --y;
        s = 0;
        while (1) {
            if (!count[x][y]) {
                count[x][y] = ++s;
            }
            else {
                std::cout << count[x][y] - 1 << " step(s) before a loop of "
                          << last - count[x][y] + 1 << " step(s)" << std::endl;
                break;
            }
            last = count[x][y];

            switch (board[x][y]) {
            case 'N':
                --x;
                break;
            case 'E':
                ++y;
                break;
            case 'S':
                ++x;
                break;
            case 'W':
                --y;
                break;
            }

            if (x < 0 || x >= num_row || y < 0 || y >= num_col) {
                std::cout << last << " step(s) to exit" << std::endl;
                break;
            }
        }
    }

    return 0;
}
