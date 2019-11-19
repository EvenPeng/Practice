#include <array>
#include <iostream>
#include <vector>

#define MAX_N 1000000

int main(void)
{
    std::array<bool, MAX_N> is_prime;
    std::array<int, MAX_N>  element;
    std::vector<int>        prime;

    int sum;

    is_prime.fill(true);
    prime.push_back(2);
    for (int i = 3; i < MAX_N; i += 2) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    element.fill(0);
    for (int i = 0; i < prime.size(); ++i) {
        for (int j = i; j < prime.size(); ++j) {
            sum = prime[i] + prime[j];
            if (sum >= MAX_N) break;
            if (!element[sum]) element[sum] = prime[i];
        }
    }

    while (1) {
        std::cin >> sum;
        if (!sum) break;

        std::cout << sum << ":" << std::endl;
        if (!element[sum])
            std::cout << "NO WAY!" << std::endl;
        else
            std::cout << element[sum] << "+" << sum - element[sum] << std::endl;
    }

    return 0;
}
