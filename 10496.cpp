#include <array>
#include <cmath>
#include <iostream>

struct Tile {
    int x, y;
};

int                                 num_beeper;
std::array<Tile, 11>                beeper;
std::array<std::array<int, 11>, 11> dist;

int distance(int x, int y)
{
    return std::abs(beeper[x].x - beeper[y].x) +
           std::abs(beeper[x].y - beeper[y].y);
}

int explore(int j, int seen)
{
    int cost = 400;

    for (int i = 1; i <= num_beeper; ++i) {
        if (!(seen & (1 << i))) {
            cost = std::min(cost, dist[i][j] + explore(i, seen + (1 << i)));
        }
    }

    return cost == 400 ? distance(j, 0) : cost;
}

int main(void)
{
    int num_case, num_row, num_col;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> num_row >> num_col;
        std::cin >> beeper[0].x >> beeper[0].y;

        std::cin >> num_beeper;
        for (int i = 1; i <= num_beeper; ++i) {
            std::cin >> beeper[i].x >> beeper[i].y;
        }

        for (int i = 0; i <= num_beeper; ++i) {
            dist[i][i] = 0;
            for (int j = i + 1; j <= num_beeper; ++j) {
                dist[i][j] = distance(i, j);
                dist[j][i] = dist[i][j];
            }
        }

        std::cout << "The shortest path has length " << explore(0, 1)
                  << std::endl;
    }

    return 0;
}
