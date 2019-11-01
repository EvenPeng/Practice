#include <iostream>

int main(void)
{
    int num_cases = 0, num_question[13], required;

    while (1) {
        std::cin >> num_question[0];
        if (num_question[0] < 0) break;

        for (int i = 1; i <= 12; ++i)
            std::cin >> num_question[i];

        std::cout << "Case " << ++num_cases << ":" << std::endl;
        for (int i = 0; i < 12; ++i) {
            std::cin >> required;
            if (num_question[i] >= required) {
                num_question[i] -= required;
                std::cout << "No problem! :D" << std::endl;
            }
            else {
                std::cout << "No problem. :(" << std::endl;
            }
            num_question[i + 1] += num_question[i];
        }
    }

    return 0;
}
