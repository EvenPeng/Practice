#include <algorithm>
#include <array>
#include <iostream>

int main(void)
{
    int num_cases, N, K, x;

    std::array<std::array<bool, 100>, 10000> exist;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> N >> K;

        exist[0].fill(false);
        std::cin >> x;
        x           = std::abs(x) % K;
        exist[0][x] = true;

        for (int i = 1; i < N; ++i) {
            std::cin >> x;
            exist[i].fill(false);
            for (int j = 0; j < K; ++j) {
                if (exist[i - 1][j]) {
                    exist[i][std::abs(j + x) % K] = true;
                    exist[i][std::abs(j - x) % K] = true;
                }
            }
        }

        if (exist[N - 1][0]) {
            std::cout << "Divisible" << std::endl;
        }
        else {
            std::cout << "Not divisible" << std::endl;
        }
    }

    return 0;
}
