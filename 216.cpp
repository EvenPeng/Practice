#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>

struct Computer {
    int x, y;
} computers[10];
int    num_computer;
double dist[10][10], best_sum;
bool   seen[10];
int    sequence[10], best_sequence[10];

double calculate_dist(const Computer &i, const Computer &j)
{
    return std::sqrt(
        double((i.x - j.x) * (i.x - j.x) + (i.y - j.y) * (i.y - j.y)));
}

void exhaustive(int left, double sum)
{
    if (left > -1) {
        if (sum > best_sum) return;
        for (int i = 0; i < num_computer; ++i) {
            if (!seen[i]) {
                seen[i]        = true;
                sequence[left] = i;
                exhaustive(left - 1, sum + dist[i][sequence[left + 1]]);
                seen[i] = false;
            }
        }
    }
    else if (sum < best_sum) {
        best_sum = sum;
        memcpy(best_sequence, sequence, sizeof(sequence));
    }
}

int main(void)
{
    int case_index = 0;

    std::cout << std::fixed << std::setprecision(2);
    memset(seen, false, sizeof(seen));
    while (1) {
        std::cin >> num_computer;
        if (!num_computer) break;

        for (int i = 0; i < num_computer; ++i) {
            memset(dist[i], 0, sizeof(dist[0]));
            std::cin >> computers[i].x >> computers[i].y;
            for (int j = 0; j < i; ++j) {
                dist[i][j] = calculate_dist(computers[i], computers[j]) + 16;
                dist[j][i] = dist[i][j];
            }
        }

        best_sum = 2500;
        for (int i = 0; i < num_computer; ++i) {
            seen[i]                    = true;
            sequence[num_computer - 1] = i;
            exhaustive(num_computer - 2, 0);
            seen[i] = false;
        }

        std::cout
            << "**********************************************************"
            << std::endl;
        std::cout << "Network #" << ++case_index << std::endl;
        for (int i = 0; i < num_computer - 1; ++i) {
            std::cout << "Cable requirement to connect ("
                      << computers[best_sequence[i]].x << ","
                      << computers[best_sequence[i]].y << ") to ("
                      << computers[best_sequence[i + 1]].x << ","
                      << computers[best_sequence[i + 1]].y << ") is "
                      << dist[best_sequence[i]][best_sequence[i + 1]]
                      << " feet." << std::endl;
        }
        std::cout << "Number of feet of cable required is " << best_sum << "."
                  << std::endl;
    }

    return 0;
}
