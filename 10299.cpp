#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main(void)
{
    bool          is_prime;
    unsigned long target, count;

    std::vector<unsigned long> prime  = {2, 3, 5, 7, 11, 13};
    std::vector<unsigned long> square = {4, 9, 25, 49, 121, 169};

    for (int i = 17; i < 31624; i += 2) {
        is_prime = true;
        for (int j = 0; is_prime && square[j] <= i; ++j) {
            is_prime = i % prime[j] != 0;
        }
        if (is_prime) {
            prime.push_back(i);
            square.push_back(i * i);
        }
    }

    while (1) {
        std::cin >> target;
        if (!target) break;
        if (target == 1) {
            std::cout << "0" << std::endl;
            continue;
        }

        count = target;
        for (int i = 0; i < square.size() && square[i] <= target; ++i) {
            if (target % prime[i] == 0) {
                count -= count / prime[i];
                do {
                    target /= prime[i];
                } while (target % prime[i] == 0);
            }
        }
        if (target > 1) count -= count / target;

        std::cout << count << std::endl;
    }

    return 0;
}
