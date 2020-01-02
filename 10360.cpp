#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct Rat {
    int x, y, p;
};

bool sort_rat_x(const Rat &x, const Rat &y)
{
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}

bool sort_rat_y(const Rat &x, const Rat &y)
{
    return x.y == y.y ? x.x < y.x : x.y < y.y;
}

int main(void)
{
    int num_case, num_rat, radius, diameter;
    int max_x, max_y, latest_x, latest_y, max_rat, sum_rat;

    std::array<Rat, 20000> rat;
    std::vector<Rat>       sub_rat;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> radius >> num_rat;
        diameter = radius * 2 + 1;

        for (int i = 0; i < num_rat; ++i) {
            std::cin >> rat[i].x >> rat[i].y >> rat[i].p;
        }

        std::sort(rat.begin(), rat.begin() + num_rat, sort_rat_x);

        max_rat = 0;
        for (int i = 0; i < num_rat; ++i) {
            sub_rat.clear();
            sub_rat.push_back(rat[i]);
            sum_rat = rat[i].p;
            for (int j = i + 1; j < num_rat && rat[j].x < rat[i].x + diameter;
                 ++j) {
                if (rat[i].y - diameter < rat[j].y &&
                    rat[j].y < rat[i].y + diameter) {
                    sub_rat.push_back(rat[j]);
                    sum_rat += rat[j].p;
                }
            }

            if (sum_rat <= max_rat) continue;

            if (sub_rat.size() > 1) {
                std::sort(sub_rat.begin(), sub_rat.end(), sort_rat_y);
            }

            sum_rat = 0;
            for (int l = 0, r = 0; r < sub_rat.size(); ++r) {
                while (l < r && sub_rat[l].y + diameter <= sub_rat[r].y) {
                    sum_rat -= sub_rat[l++].p;
                }

                sum_rat += sub_rat[r].p;
                if (sum_rat > max_rat) {
                    latest_x = sub_rat[l].x;
                    latest_y = sub_rat[l].y;
                    for (int j = l + 1; j <= r; ++j) {
                        latest_x = std::max(latest_x, sub_rat[j].x);
                        latest_y = std::max(latest_y, sub_rat[j].y);
                    }
                    max_rat = sum_rat;
                    max_x   = std::max(latest_x - radius, 0);
                    max_y   = std::max(latest_y - radius, 0);
                }
            }
        }

        std::cout << max_x << " " << max_y << " " << max_rat << std::endl;
    }

    return 0;
}
