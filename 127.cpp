#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool match(const std::string &x, const std::string &y)
{
    return x[0] == y[0] || x[1] == y[1];
}

int main(void)
{
    std::array<std::string, 52>  card;
    std::vector<std::stack<int>> tile;

    while (1) {
        std::cin >> card[0];
        if (card[0][0] == '#') break;

        for (int i = 1; i < 52; ++i)
            std::cin >> card[i];

        tile.clear();
        tile.resize(52);
        for (int i = 0; i < 52; ++i) {
            tile[i].push(i);
        }

        int idx = 0;
        while (idx < tile.size()) {
            if (idx - 3 > -1 &&
                match(card[tile[idx].top()], card[tile[idx - 3].top()])) {
                tile[idx - 3].push(tile[idx].top());
                tile[idx].pop();
                if (!tile[idx].size()) {
                    tile.erase(tile.begin() + idx);
                }
                idx -= 3;
            }
            else if (idx - 1 > -1 &&
                     match(card[tile[idx].top()], card[tile[idx - 1].top()])) {
                tile[idx - 1].push(tile[idx].top());
                tile[idx].pop();
                if (!tile[idx].size()) {
                    tile.erase(tile.begin() + idx);
                }
                idx -= 1;
            }
            else {
                ++idx;
            }
        }

        if (tile.size() == 1)
            std::cout << "1 pile remaining:";
        else
            std::cout << tile.size() << " piles remaining:";
        for (const auto &e : tile)
            std::cout << " " << e.size();
        std::cout << std::endl;
    }

    return 0;
}
