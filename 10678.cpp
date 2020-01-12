#include <cmath>
#include <iomanip>
#include <iostream>

#define M_PI 3.14159265358979323846

int main(void)
{
    std::ios::sync_with_stdio(false);

    int    num_case;
    double d, l, a, b;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> d >> l;
        a = std::sqrt((l / 2 * l / 2) - (d / 2 * d / 2));
        b = l / 2;
        std::cout << std::fixed << std::setprecision(3) << M_PI * a * b
                  << std::endl;
    }

    return 0;
}
