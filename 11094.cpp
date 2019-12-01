#include <algorithm>
#include <array>
#include <iostream>
#include <string>

char region;
int  num_row, num_col;

std::array<std::string, 20> land;

int explore(const int x, const int y)
{
    if (land[x][y] != region) return 0;
    int count  = 1;
    land[x][y] = region + 1;
    if (0 < x) count += explore(x - 1, y);
    if (x + 1 < num_row) count += explore(x + 1, y);
    if (0 < y) count += explore(x, y - 1);
    else count += explore(x, num_col-1);
    if (y + 1 < num_col) count += explore(x, y + 1);
    else count += explore(x, 0);
    return count;
}

int main(void)
{
    int x, y, max_count;

    while (std::cin >> num_row >> num_col) {
        for (int i = 0; i < num_row; ++i) {
            std::cin >> land[i];
        }

        std::cin >> x >> y;
        region = land[x][y];
        explore(x, y);

        max_count = 0;
        for (int i = 0; i < num_row; ++i) {
            for (int j = 0; j < num_col; ++j) {
                if (land[i][j] == region) {
                    max_count = std::max(max_count, explore(i, j));
                }
            }
        }

        std::cout << max_count << std::endl;
    }

    return 0;
}
