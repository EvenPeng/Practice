#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

struct Location {
    double x, y;
};

double Distance(const Location &x, const Location &y)
{
    double dx = x.x - y.x;
    double dy = x.y - y.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main(void)
{
    int    num_build, num_link;
    int    x, y, select;
    double sum;

    std::array<bool, 1000>             seen;
    std::array<double, 1000>           dist;
    std::array<Location, 1000>         build;
    std::array<std::vector<int>, 1000> linked;
    std::queue<int>                    q;

    while (std::cin >> num_build) {
        for (int i = 0; i < num_build; ++i) {
            std::cin >> build[i].x >> build[i].y;
            linked[i].clear();
        }

        std::cin >> num_link;
        for (int i = 0; i < num_link; ++i) {
            std::cin >> x >> y;
            --x;
            --y;
            linked[x].push_back(y);
            linked[y].push_back(x);
        }

        sum = 0;
        seen.fill(false);
        seen[0] = true;
        q.push(0);
        for (int i = 0; i < num_build; ++i) {
            dist[i] = Distance(build[i], build[0]);
        }
        while (!q.empty()) {
            for (auto const &j : linked[q.front()]) {
                if (!seen[j]) {
                    seen[j] = true;
                    q.push(j);
                    for (int i = 0; i < num_build; ++i) {
                        if (!seen[i])
                            dist[i] =
                                std::min(dist[i], Distance(build[i], build[j]));
                    }
                }
            }
            q.pop();
        }

        while (1) {
            select = 0;
            while (select < num_build && seen[select])
                ++select;
            if (select == num_build) break;

            for (int i = select + 1; i < num_build; ++i) {
                if (!seen[i] && dist[i] < dist[select]) {
                    select = i;
                }
            }

            sum += dist[select];
            seen[select] = true;
            for (int i = 0; i < num_build; ++i) {
                if (!seen[i])
                    dist[i] =
                        std::min(dist[i], Distance(build[i], build[select]));
            }
            q.push(select);
            while (!q.empty()) {
                for (auto const &j : linked[q.front()]) {
                    if (!seen[j]) {
                        seen[j] = true;
                        q.push(j);
                        for (int i = 0; i < num_build; ++i) {
                            if (!seen[i])
                                dist[i] = std::min(
                                    dist[i], Distance(build[i], build[j]));
                        }
                    }
                }
                q.pop();
            }
        }

        std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    }

    return 0;
}
