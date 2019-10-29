#include <algorithm>
#include <iostream>

int count(int x, int y)
{
    if (x > y) std::swap(x, y);
    if (x == 0) return 0;
    if (x == 1) return y;
    if (x == 2) return (4 * (y / 4) + 2 * (y % 4 > 2 ? 2 : y % 4));
    return (x * y + 1) / 2;
}

int main(void)
{
    int row, col;

    while (1) {
        std::cin >> row >> col;
        if (!row && !col) break;
        std::cout << count(row, col) << " knights may be placed on a " << row
                  << " row " << col << " column board." << std::endl;
    }

    return 0;
}
