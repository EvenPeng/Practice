#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <string>

#define N 10000

struct Walk {
    std::string path;
    int         curr;
};

int main(void)
{
    bool        done;
    int         num_case, num_road, num_query;
    int         src_id, dst_id;
    std::string src, dst;
    Walk        walk;

    std::array<int, N>           level;
    std::array<std::string, N>   head;
    std::map<std::string, int>   name;
    std::array<std::vector<int>, N> connect;

    std::cin >> num_case;
    while (num_case--) {
        name.clear();
        std::cin >> num_road >> num_query;

        for (int i = 0; i < num_road; ++i) {
            std::cin >> src >> dst;
            if (!name[src]) {
                name[src]       = name.size();
                head[name[src]] = src.substr(0, 1);
                connect[name[src]].clear();
            }
            if (!name[dst]) {
                name[dst]       = name.size();
                head[name[dst]] = dst.substr(0, 1);
                connect[name[dst]].clear();
            }
            src_id = name[src];
            dst_id = name[dst];

            connect[src_id].push_back(dst_id);
            connect[dst_id].push_back(src_id);
        }

        for (int k = 0; k < num_query; ++k) {
            std::cin >> src >> dst;
            src_id = name[src];
            dst_id = name[dst];

            std::queue<Walk> q;
            q.push({head[src_id], src_id});
            done = false;
            level.fill(N);
            level[src_id] = 1;
            while (!done) {
                walk = q.front();
                q.pop();
                for (const auto i : connect[walk.curr]) {
                    if (level[i] >= walk.path.size()) {
                        if (i == dst_id) {
                            std::cout << walk.path + head[dst_id] << std::endl;
                            done = true;
                            break;
                        }
                        else {
                            q.push({walk.path + head[i], i});
                            level[i] = walk.path.size() + 1;
                        }
                    }
                }
            }
        }

        if (num_case) std::cout << std::endl;
    }

    return 0;
}
