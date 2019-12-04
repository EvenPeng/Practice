#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int size, max_count;

std::vector<int>           tile, place;
std::array<std::string, 4> board;

bool conflict(int x1, int y1, int x2, int y2)
{
    if (x1 == x2) {
        if (y1 > y2) std::swap(y1, y2);
        for (int i = y1 + 1; i < y2; ++i) {
            if (board[x1][i] == 'X') return false;
        }
        return true;
    }
    else if (y1 == y2) {
        if (x1 > x2) std::swap(x1, x2);
        for (int i = x1 + 1; i < x2; ++i) {
            if (board[i][y1] == 'X') return false;
        }
        return true;
    }

    return false;
}

void solve()
{
    bool valid;
    int  x1, x2, y1, y2;
    for (int i = 0; i < tile.size(); ++i) {
        valid = true;
        x1    = tile[i] / size;
        y1    = tile[i] % size;

        for (const int &p : place) {
            x2 = p / size;
            y2 = p % size;
            if (conflict(x1, y1, x2, y2)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            place.push_back(tile[i]);
            if (place.size() > max_count) max_count = place.size();
            solve();
            place.pop_back();
        }
    }
}

int main(void)
{
    while (1) {
        tile.clear();
        place.clear();

        std::cin >> size;
        if (!size) break;
        for (int i = 0; i < size; ++i) {
            std::cin >> board[i];
            for (int j = 0; j < size; ++j) {
                if (board[i][j] == '.') tile.push_back(i * size + j);
            }
        }

        max_count = 0;
        solve();

        std::cout << max_count << std::endl;
    }

    return 0;
}
