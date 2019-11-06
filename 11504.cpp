#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>

int                 num_cases, num_domino, num_line;
bool                seen[100001];
std::map<int, bool> hit[100001];
std::stack<int>     order;

void travel(int x)
{
    seen[x] = true;
    for (const auto &i : hit[x])
        if (!seen[i.first]) travel(i.first);
    order.push(x);
}

void back_travel(int x)
{
    seen[x] = true;
    for (const auto &i : hit[x])
        if (!seen[i.first]) travel(i.first);
}

int main(void)
{
    int src, dst, count;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num_domino >> num_line;

        for (int i = 1; i <= num_domino; ++i)
            hit[i].clear();

        for (int i = 0; i < num_line; ++i) {
            std::cin >> src >> dst;
            hit[src][dst] = true;
        }

        memset(seen, false, sizeof(seen));
        for (int i = 1; i <= num_domino; ++i) {
            if (!seen[i]) travel(i);
        }

        count = 0;
        memset(seen, false, sizeof(seen));
        while (!order.empty()) {
            if (!seen[order.top()]) {
                ++count;
                back_travel(order.top());
            }
            order.pop();
        }

        std::cout << count << std::endl;
    }

    return 0;
}
