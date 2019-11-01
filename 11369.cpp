#include <algorithm>
#include <iostream>

int main(void)
{
    int num_cases, num_item, discount;
    int prices[20000];

    std::cin >> num_cases;
    while (num_cases--) {
        std::cin >> num_item;
        for (int i = 0; i < num_item; ++i)
            std::cin >> prices[i];
        std::sort(prices, prices + num_item);

        discount = 0;
        for (int i = num_item - 3; i > -1; i -= 3)
            discount += prices[i];
        std::cout << discount << std::endl;
    }

    return 0;
}
