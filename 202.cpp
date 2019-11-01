#include <iomanip>
#include <iostream>
#include <map>

int main(void)
{
    int  dividend, divisor, digits[10000], num_digits, repeat_head, num_repeat;
    std::map<int, int> exist;

    while (std::cin >> dividend >> divisor) {
        exist.clear();
        std::cout << dividend << "/" << divisor << " = " << dividend / divisor
                  << ".";

        num_digits = 0;
        dividend %= divisor;
        while (1) {
            exist[dividend] = num_digits + 1;
            dividend *= 10;
            digits[num_digits++] = dividend / divisor;
            dividend %= divisor;

            if (exist[dividend]) {
                repeat_head = exist[dividend] - 1;
                num_repeat  = num_digits - repeat_head;
                break;
            }
        }

        for (int i = 0; i < repeat_head && i < 50; ++i)
            std::cout << digits[i];
        if (repeat_head < 50) {
            std::cout << "(";
            for (int i = 0; i < num_repeat && repeat_head + i < 50; ++i)
                std::cout << digits[repeat_head + i];
            if (repeat_head + num_repeat >= 50) std::cout << "...";
            std::cout << ")" << std::endl;
        }
        else {
            std::cout << "..." << std::endl;
        }

        std::cout << "   " << num_repeat
                  << " = number of digits in repeating cycle\n" << std::endl;
    }

    return 0;
}
