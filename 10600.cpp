#include <algorithm>
#include <array>
#include <iostream>

struct Connection {
    int x, y, w;
};

bool sort_connection(const Connection &e1, const Connection &e2)
{
    return e1.w == e2.w ? (e1.x == e2.x ? e1.y < e2.y : e1.x < e2.x)
                        : e1.w < e2.w;
}

int main(void)
{
    bool refresh;
    int  num_cases, x, y;
    int  num_node, num_edge, count, best_cost, better_cost;

    std::array<bool, 100>         seen;
    std::array<int, 100>          selected;
    std::array<Connection, 10000> conn;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num_node >> num_edge;
        for (int i = 0; i < num_edge; ++i) {
            std::cin >> conn[i].x >> conn[i].y >> conn[i].w;
            --conn[i].x;
            --conn[i].y;
        }
        std::sort(conn.begin(), conn.begin() + num_edge, sort_connection);

        seen.fill(false);
        seen[conn[0].x] = true;
        seen[conn[0].y] = true;
        best_cost       = conn[0].w;
        count           = 0;
        selected[0]      = 0;
        refresh         = true;
        while (refresh) {
            refresh = false;
            for (int i = 0; i < num_edge; ++i) {
                if ((!seen[conn[i].x] && seen[conn[i].y]) ||
                    (seen[conn[i].x] && !seen[conn[i].y])) {
                    seen[conn[i].x] = true;
                    seen[conn[i].y] = true;
                    best_cost += conn[i].w;
                    selected[++count] = i;
                    refresh           = true;
                    break;
                }
            }
        }
        std::cout << best_cost << " ";

        better_cost = 30000;
        for (int k = 0; k < num_node - 1; ++k) {
            seen.fill(false);
            if (!k) {
                seen[conn[1].x] = true;
                seen[conn[1].y] = true;
                best_cost       = conn[1].w;
            }
            else {
                seen[conn[0].x] = true;
                seen[conn[0].y] = true;
                best_cost       = conn[0].w;
            }
            count   = 1;
            refresh = true;
            while (refresh) {
                refresh = false;
                for (int i = 0; i < num_edge; ++i) {
                    if (i != selected[k] &&
                        ((!seen[conn[i].x] && seen[conn[i].y]) ||
                         (seen[conn[i].x] && !seen[conn[i].y]))) {
                        seen[conn[i].x] = true;
                        seen[conn[i].y] = true;
                        best_cost += conn[i].w;
                        ++count;
                        refresh = true;
                        break;
                    }
                }
            }
            if (count == num_node - 1 && best_cost < better_cost)
                better_cost = best_cost;
        }

        std::cout << better_cost << std::endl;
    }

    return 0;
}
