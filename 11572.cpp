#include <algorithm>
#include <iostream>
#include <map>

int main(void)
{
    int num_case, size, max_count, x, last;

    std::map<int, int> seen;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> size;

        seen.clear();
        last      = 0;
        max_count = 0;
        for (int i = 1; i <= size; ++i) {
            std::cin >> x;
            last = std::max(last, seen[x]);
            if (max_count < i - last) {
                max_count = i - last;
            }
            seen[x] = i;
        }

        std::cout << max_count << std::endl;
    }

    return 0;
}
