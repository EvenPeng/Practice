#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

int main(void)
{
    double      s, a;
    std::string type;

    while (std::cin >> s >> a >> type) {
        if (type == "min") a /= 60;
        if (a > 180) a = 360 - a;
        double ang = a * acos(-1.0) / 180.0;
        double arc = 2.0 * (s + 6440.0) * sin(ang / 2.0);
        double cho = ang * (s + 6440.0);
        std::cout << std::fixed << std::setprecision(6) << cho << " " << arc
                  << std::endl;
    }

    return 0;
}
