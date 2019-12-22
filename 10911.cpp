#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

struct Location {
    double x, y;
};

double Distance(const Location &x, const Location &y)
{
    double dx = x.x - y.x;
    double dy = x.y - y.y;
    return dx * dx + dy * dy;
}

int main(void)
{
    int                       num_case, num_team, num_peo, x;
    double                    min_sum;
    std::string               dummy;
    std::array<Location, 16>  loc;
    std::array<double, 65537> dist;
    std::queue<int>           q;

    num_case = 0;
    while (1) {
        std::cin >> num_team;
        if (!num_team) break;
        num_peo = num_team * 2;

        dist.fill(1000000);
        for (int i = 0; i < num_peo; ++i) {
            std::cin >> dummy >> loc[i].x >> loc[i].y;
            for (int j = 0; j < i; ++j) {
                dist[(1 << i) + (1 << j)] = std::sqrt(Distance(loc[i], loc[j]));
                q.push((1 << i) + (1 << j));
            }
        }

        while (!q.empty()) {
            x = q.front();
            q.pop();
            for (int i = 0; i < num_peo; ++i) {
                if ((x & (1 << i)) == 0) {
                    for (int j = 0; j < i; ++j) {
                        if ((x & (1 << j)) == 0) {
                            if (dist[x + (1 << i) + (1 << j)] == 1000000)
                                q.push(x + (1 << i) + (1 << j));
                            dist[x + (1 << i) + (1 << j)] =
                                std::min(dist[x + (1 << i) + (1 << j)],
                                         dist[x] + dist[(1 << i) + (1 << j)]);
                        }
                    }
                }
            }
        }

        std::cout << "Case " << ++num_case << ": " << std::fixed
                  << std::setprecision(2) << dist[(1 << num_peo) - 1]
                  << std::endl;
    }

    return 0;
}
