#include <iostream>

int main(void)
{
    int num_cases, number, digits[33], num_digits;

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> number;
        if (number < 10)
            std::cout << number << std::endl;
        else {
            num_digits = 0;
            for (int i = 9; number > 1 && i > 1; --i) {
                while (number > 1 && number % i == 0) {
                    digits[num_digits++] = i;
                    number /= i;
                }
            }
            if (number == 1) {
                for (int i = num_digits - 1; i > -1; --i)
                    std::cout << digits[i];
                std::cout << std::endl;
            }
            else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
