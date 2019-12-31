#include <cmath>
#include <iostream>

/*
 *  x + y + z = A
 *  xyz = B
 *  x^2 + y^2 + z^2 = C
 *
 *  y + z = A - x
 *  yz = B / x
 *  y^2 + z^2 = C - x^2
 *
 *  (A - x)^2 - (C - x^2) = 2B / x
 *  ((A - x)^2 - (C - x^2)) * x = 2B
 *
 *  y - z = sqrt(C - x^2 - 2B/x)
 */

int main(void)
{
    bool solved;
    int  num_case;
    int  A, B, C, xA, xC;
    int  x, y, z;
    int  bound_x, bound_y;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> A >> B >> C;
        solved  = false;
        bound_x = std::min(100, std::abs(B));

        for (x = -1 * bound_x; !solved && x <= bound_x; ++x) {
            xA = (A - x) * (A - x);
            xC = C - x * x;
            xA = (xA - xC) * x;
            if (xA == 2 * B) {
                y = (A - x + int(std::sqrt(xC - 2 * B / x))) / 2;
                z = A - x - y;
                if (x != y && x != z && y != z && x * y * z == B) {
                    if (y > z) {
                        std::swap(y, z);
                    }
                    solved = true;
                    std::cout << x << " " << y << " " << z << std::endl;
                }
            }
        }

        if (!solved) {
            std::cout << "No solution." << std::endl;
        }
    }

    return 0;
}
