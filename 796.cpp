#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

struct Edge {
    int x, y;
};
std::vector<Edge> answer;

int num_server;
int connected[1000][1000], num_edge[1000];

void traversal(int root)
{
    if (num_edge[root] == 1) {
        if (connected[root][0] > root)
            answer.push_back({root, connected[root][0]});
        return;
    }

    bool no_way, seen[1000];
    int  path[1000], length;

    path[0] = root;

    for (int i = 0; i < num_edge[root]; ++i) {
        if (connected[root][i] > root) {
            no_way = false;
            memset(seen, false, sizeof(seen));
            seen[root]               = true;
            seen[connected[root][i]] = true;
            path[1]                  = connected[root][i];
            length                   = 2;
            while (length > 1) {
                no_way = true;
                for (int j = 0; j < num_edge[path[length - 1]]; ++j) {
                    int next = connected[path[length - 1]][j];
                    if (path[length - 2] != next) {
                        if (!seen[next]) {
                            seen[next]     = true;
                            no_way         = false;
                            path[length++] = next;
                        }
                        else if (next == root) {
                            length = 1;
                            break;
                        }
                    }
                }
                if (no_way) {
                    if (length == 2)
                        answer.push_back({root, connected[root][i]});
                    --length;
                }
            }
        }
    }
}

int main(void)
{
    int         src, dst;
    std::string buffer;

    while (std::cin >> num_server) {
        for (int i = 0; i < num_server; ++i) {
            std::cin >> src >> buffer;
            num_edge[src] = std::stoi(buffer.substr(1, buffer.size() - 2));
            for (int j = 0; j < num_edge[src]; ++j) {
                std::cin >> connected[src][j];
            }
            std::sort(connected[src], connected[src] + num_edge[src]);
        }

        answer.clear();
        for (int i = 0; i < num_server; ++i)
            traversal(i);

        std::cout << answer.size() << " critical links" << std::endl;
        for (auto &e : answer)
            std::cout << e.x << " - " << e.y << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
