#include <array>
#include <iostream>

int num_nodes, max_count;

std::array<bool, 100>                  seen, black, ans;
std::array<std::array<bool, 100>, 100> adj_matrix;

bool valid(int x)
{
    for (int i = num_nodes - 1; i > -1; --i) {
        if (adj_matrix[x][i] && black[i]) return false;
    }
    return true;
}

void traversal(int x, int count)
{
    bool done = true;

    ++count;
    black[x] = true;
    for (int i = num_nodes - 1; i > -1; --i) {
        if (!black[i] && valid(i)) {
            traversal(i, count);
            done = false;
        }
    }
    if (done && max_count < count) {
        max_count = count;
        ans       = black;
    }

    black[x] = false;
}

int main(void)
{
    bool first;
    int  num_cases, num_edges, x, y, base_count;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num_nodes >> num_edges;
        for (int i = 0; i < num_nodes; ++i)
            adj_matrix[i].fill(false);

        black.fill(true);
        for (int i = 0; i < num_edges; ++i) {
            std::cin >> x >> y;
            --x;
            --y;
            adj_matrix[x][y] = true;
            adj_matrix[y][x] = true;
            black[x]         = false;
            black[y]         = false;
        }

        base_count = 0;
        for (int i = 0; i < num_nodes; ++i) {
            if (black[i]) ++base_count;
        }
        ans = black;

        max_count = 0;
        for (int i = num_nodes - 1; i > -1; --i) {
            if (!black[i]) traversal(i, 0);
        }

        std::cout << base_count + max_count << std::endl;
        first = true;
        for (int i = 0; i < num_nodes; ++i) {
            if (ans[i]) {
                if (!first) std::cout << " ";
                std::cout << i + 1;
                first = false;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
