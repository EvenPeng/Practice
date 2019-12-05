#include <algorithm>
#include <array>
#include <iostream>

int main(void)
{
    int width, height, num_rect, sum;
    int x_min, y_min, x_max, y_max, dx, dy;

    std::array<std::array<bool, 500>, 500> board;

    while (1) {
        std::cin >> width >> height >> num_rect;
        if (!width && !height && !num_rect) break;

        for (int i = 0; i < width; ++i) {
            board[i].fill(true);
        }

        for (int k = 0; k < num_rect; ++k) {
            std::cin >> x_min >> y_min >> x_max >> y_max;
            if (x_min > x_max) std::swap(x_min, x_max);
            if (y_min > y_max) std::swap(y_min, y_max);
            --x_min;
            --x_max;
            --y_min;
            --y_max;
            for (int i = x_min; i <= x_max; ++i) {
                for (int j = y_min; j <= y_max; ++j) {
                    board[i][j] = false;
                }
            }
        }

        sum = 0;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (board[i][j]) ++sum;
            }
        }

        if (!sum)
            std::cout << "There is no empty spots." << std::endl;
        else if (sum == 1)
            std::cout << "There is one empty spot." << std::endl;
        else
            std::cout << "There are " << sum << " empty spots." << std::endl;
    }

    return 0;
}
