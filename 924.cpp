#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

int main(void)
{
    int                                num_employee, num_cases;
    std::array<std::vector<int>, 2500> friends;
    std::queue<int>                    wait;
    std::array<bool, 2500>             seen;
    std::array<int, 2500>              expand, receive;
    int                                size, target, left, max_day;

    std::cin >> num_employee;
    for (int i = 0; i < num_employee; ++i) {
        std::cin >> size;
        friends[i].resize(size);
        for (int j = 0; j < size; ++j)
            std::cin >> friends[i][j];
    }

    std::cin >> num_cases;
    while (num_cases--) {
        seen.fill(false);
        expand.fill(0);
        receive.fill(0);

        std::cin >> target;
        wait.push(target);
        seen[target] = true;
        max_day      = 0;
        left         = num_employee;
        while (!wait.empty()) {
            auto curr = wait.front();

            for (const auto &f : friends[curr]) {
                if (!seen[f]) {
                    wait.push(f);
                    seen[f]    = true;
                    receive[f] = receive[curr] + 1;
                    ++expand[receive[curr]];
                }
            }

            if (expand[receive[curr]] > expand[max_day])
                max_day = receive[curr];

            wait.pop();
            if (left + expand[receive[curr]] < expand[max_day] &&
                receive[curr] != max_day) {
                while (!wait.empty())
                    wait.pop();
            }
        }

        if (!expand[0])
            std::cout << 0 << std::endl;
        else
            std::cout << expand[max_day] << " " << ++max_day << std::endl;
    }

    return 0;
}
