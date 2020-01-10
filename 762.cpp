#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

int main(void)
{
    bool first = true;
    int  num_city;
    int  src_id, dst_id;

    std::string                   src, dst;
    std::vector<std::vector<int>> conn;
    std::vector<std::string>      city;
    std::map<std::string, int>    city2id;
    std::queue<int>               q;
    std::stack<int>               path;
    std::vector<int>              parent;

    while (std::cin >> num_city) {
        if (!first)
            std::cout << std::endl;
        else
            first = false;

        city.clear();
        city2id.clear();
        conn.clear();
        for (int i = 0; i < num_city; ++i) {
            std::cin >> src >> dst;
            if (!city2id[src]) {
                city2id[src] = city2id.size();
                city.push_back(src);
                conn.push_back(std::vector<int>{});
            }
            if (!city2id[dst]) {
                city2id[dst] = city2id.size();
                city.push_back(dst);
                conn.push_back(std::vector<int>{});
            }

            if (src != dst) {
                conn[city2id[src] - 1].push_back(city2id[dst] - 1);
                conn[city2id[dst] - 1].push_back(city2id[src] - 1);
            }
        }
        std::cin >> src >> dst;

        src_id = city2id[src] - 1;
        dst_id = city2id[dst] - 1;

        if (src_id == -1 || dst_id == -1) {
            std::cout << "No route" << std::endl;
            continue;
        }

        q.push(src_id);
        parent.assign(city2id.size(), -1);
        parent[src_id] = src_id;
        while (!q.empty()) {
            src_id = q.front();
            q.pop();
            if (parent[dst_id] == -1) {
                for (auto const &x : conn[src_id]) {
                    if (parent[x] == -1) {
                        parent[x] = src_id;
                        q.push(x);
                    }
                }
            }
        }

        if (parent[dst_id] == -1) {
            std::cout << "No route" << std::endl;
        }
        else {
            while (parent[dst_id] != dst_id) {
                path.push(dst_id);
                dst_id = parent[dst_id];
            }
            src_id = dst_id;
            while (!path.empty()) {
                dst_id = path.top();
                path.pop();
                std::cout << city[src_id] << " " << city[dst_id] << std::endl;
                src_id = dst_id;
            }
        }
    }

    return 0;
}
