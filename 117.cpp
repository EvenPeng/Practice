#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define INF 999999

std::array<bool, 26>                seen;
std::array<std::array<int, 26>, 26> path;

int travel(int src, int dst, int cost)
{
    if (src != dst) {
        int min_cost = INF;
        seen[src]    = true;
        for (int i = 0; i < 26; ++i) {
            if (!seen[i] && path[src][i] < INF) {
                min_cost =
                    std::min(min_cost, travel(i, dst, cost + path[src][i]));
            }
        }
        seen[src] = false;
        return min_cost;
    }
    else {
        return cost;
    }
}

int main(void)
{
    int                 x, y, l, cost;
    std::string         buffer;
    std::vector<int>    odd;
    std::array<int, 26> count;

    while (std::cin >> buffer) {
        cost = 0;
        count.fill(0);
        for (int i = 0; i < 26; ++i) {
            path[i].fill(INF);
        }

        while (buffer != "deadend") {
            l = int(buffer.size());
            x = int(buffer[0] - 'a');
            y = int(buffer[l - 1] - 'a');
            ++count[x];
            ++count[y];
            cost += l;
            path[x][y] = std::min(l, path[x][y]);
            path[y][x] = std::min(l, path[y][x]);
            std::cin >> buffer;
        }

        odd.clear();
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2) {
                odd.push_back(i);
            }
        }

        if (odd.size()) {
            seen.fill(false);
            cost += travel(odd.front(), odd.back(), 0);
        }
        std::cout << cost << std::endl;
    }

    return 0;
}
