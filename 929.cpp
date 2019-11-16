#include <array>
#include <iostream>
#include <queue>

struct Tile {
    int x, y, dist;
};

bool operator<(const Tile &x, const Tile &y) { return x.dist > y.dist; }
bool operator>(const Tile &x, const Tile &y) { return x.dist < y.dist; }

int main(void)
{
    int num_cases, num_row, num_col;

    Tile curr;

    std::array<std::array<bool, 1000>, 1000> seen;
    std::array<std::array<int, 1000>, 1000>  maze;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num_row >> num_col;
        for (int i = 0; i < num_row; ++i) {
            seen[i].fill(false);
            for (int j = 0; j < num_col; ++j)
                std::cin >> maze[i][j];
        }

        std::priority_queue<Tile> path;
        path.push({0, 0, maze[0][0]});
        seen[0][0] = true;
        while (1) {
            curr = path.top();
            path.pop();
            if (curr.x == num_row - 1 && curr.y == num_col - 1) {
                std::cout << curr.dist << std::endl;
                break;
            }

            if (curr.x - 1 > -1 && !seen[curr.x - 1][curr.y]) {
                seen[curr.x - 1][curr.y] = true;
                path.push(
                    {curr.x - 1, curr.y, curr.dist + maze[curr.x - 1][curr.y]});
            }
            if (curr.x + 1 < num_row && !seen[curr.x + 1][curr.y]) {
                path.push(
                    {curr.x + 1, curr.y, curr.dist + maze[curr.x + 1][curr.y]});
            }
            if (curr.y - 1 > -1 && !seen[curr.x][curr.y - 1]) {
                seen[curr.x][curr.y - 1] = true;
                path.push(
                    {curr.x, curr.y - 1, curr.dist + maze[curr.x][curr.y - 1]});
            }
            if (curr.y + 1 < num_col && !seen[curr.x][curr.y + 1]) {
                seen[curr.x][curr.y + 1] = true;
                path.push(
                    {curr.x, curr.y + 1, curr.dist + maze[curr.x][curr.y + 1]});
            }
        }
    }

    return 0;
}
