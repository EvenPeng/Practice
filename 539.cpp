#include <array>
#include <iostream>
#include <map>
#include <queue>

struct Edge {
    int u, v;
};

struct Path {
    int u, v;
    int size;
    int mask;
};

int main(void)
{
    int  num_node, num_edge, max_len;
    Path path;

    std::array<Edge, 25> edge;
    std::map<int, bool>  seen;
    std::queue<Path>     q;

    while (1) {
        std::cin >> num_node >> num_edge;
        if (!num_node && !num_edge) break;

        for (int i = 0; i < num_edge; ++i) {
            std::cin >> edge[i].u >> edge[i].v;
            q.push({edge[i].u, edge[i].v, 1, (1 << i)});
            seen[(1 << i)] = true;
        }

        max_len = 0;
        seen.clear();
        while (!q.empty()) {
            path = q.front();
            q.pop();

            if (path.size > max_len) {
                max_len = path.size;
            }

            for (int i = 0; i < num_edge; ++i) {
                if (path.mask & (1 << i) || seen[path.mask + (1 << i)])
                    continue;
                if (edge[i].u == path.u) {
                    q.push({edge[i].v, path.v, path.size + 1,
                            path.mask + (1 << i)});
                    seen[path.mask + (1 << i)] = true;
                }
                if (edge[i].u == path.v) {
                    q.push({path.u, edge[i].v, path.size + 1,
                            path.mask + (1 << i)});
                    seen[path.mask + (1 << i)] = true;
                }
                if (edge[i].v == path.u) {
                    q.push({edge[i].u, path.v, path.size + 1,
                            path.mask + (1 << i)});
                    seen[path.mask + (1 << i)] = true;
                }
                if (edge[i].v == path.v) {
                    q.push({path.u, edge[i].u, path.size + 1,
                            path.mask + (1 << i)});
                    seen[path.mask + (1 << i)] = true;
                }
            }
        }

        std::cout << max_len << std::endl;
    }

    return 0;
}
