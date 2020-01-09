#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int num_city, step;

std::array<bool, 100>             seen, camera;
std::array<int, 100>              count, low;
std::array<std::vector<int>, 100> connected;

void explore(int x, int parent)
{
    int num_child = 0;
    seen[x]       = true;
    count[x] = low[x] = ++step;

    for (auto const &i : connected[x]) {
        if (!seen[i]) {
            explore(i, x);
            low[x] = std::min(low[x], low[i]);
            if (parent != -1 && low[i] >= count[x]) {
                camera[x] = true;
            }
            ++num_child;
        }
        else {
            low[x] = std::min(low[x], count[i]);
        }
    }

    if (parent == -1 && num_child > 1) {
        camera[x] = true;
    }
}

int main(void)
{
    int idx, num_route, num_cam;

    std::string                  src, dst;
    std::array<std::string, 100> city;
    std::map<std::string, int>   city2id;

    idx = 0;
    while (1) {
        std::cin >> num_city;
        if (!num_city) break;

        city2id.clear();
        for (int i = 0; i < num_city; ++i) {
            std::cin >> city[i];
        }
        std::sort(city.begin(), city.begin() + num_city);
        for (int i = 0; i < num_city; ++i) {
            city2id[city[i]] = i;
            connected[i].clear();
        }

        std::cin >> num_route;
        for (int i = 0; i < num_route; ++i) {
            std::cin >> src >> dst;
            connected[city2id[src]].push_back(city2id[dst]);
            connected[city2id[dst]].push_back(city2id[src]);
        }

        seen.fill(false);
        camera.fill(false);
        count.fill(0);
        low.fill(0);
        step = 0;
        for (int i = 0; i < num_city; ++i) {
            if (!seen[i]) explore(i, -1);
        }

        num_cam = 0;
        for (int i = 0; i < num_city; ++i) {
            if (camera[i]) ++num_cam;
        }

        if (idx) std::cout << std::endl;
        std::cout << "City map #" << ++idx << ": " << num_cam
                  << " camera(s) found" << std::endl;
        for (int i = 0; i < num_city; ++i) {
            if (camera[i]) std::cout << city[i] << std::endl;
        }
    }

    return 0;
}
