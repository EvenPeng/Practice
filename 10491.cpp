#include <iomanip>
#include <iostream>

int main(void)
{
    double num_cow, num_car, num_show, total, num_select, prob;

    while (std::cin >> num_cow >> num_car >> num_show) {
        total      = num_cow + num_car;
        num_select = total - num_show - 1;
        prob       = (num_cow / total) * (num_car / num_select) +
               (num_car / total) * ((num_car - 1) / num_select);
        std::cout << std::fixed << std::setprecision(5) << prob << std::endl;
    }

    return 0;
}
