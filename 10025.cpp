#include <cmath>
#include <iostream>

int main(void)
{
    bool is_even;
    int  num_case;
    long n, k, max_sum;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> k;

        k       = std::abs(k);
        is_even = (k % 2 == 0);

        n = long(std::ceil(std::sqrt(k * 2)));
        n = ((n - 1) / 4 * 4) + 1;
        if (is_even) n += 2;
        max_sum = n * (n + 1) / 2;

        while (max_sum < k) {
            max_sum += ++n;
            if (max_sum >= k) break;
            n += 3;
            max_sum = n * (n + 1) / 2;
        }

        std::cout << n << std::endl;
        if (num_case) std::cout << std::endl;
    }

    return 0;
}
