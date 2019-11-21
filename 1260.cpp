#include <array>
#include <iostream>

int main(void)
{
    int                   num_cases, num, count;
    std::array<int, 1000> seq;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num;
        for (int i = 0; i < num; ++i)
            std::cin >> seq[i];

        count = 0;
        for (int i = 0; i < num; ++i) {
            for (int j = 0; j < i; ++j) {
                if (seq[j] <= seq[i]) ++count;
            }
        }

        std::cout << count << std::endl;
    }

    return 0;
}
