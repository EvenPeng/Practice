#include <array>
#include <iostream>

int main(void)
{
    bool                            first, is_prime;
    int                             count = 4;
    std::array<unsigned int, 46340> prime, square;
    std::array<bool, 1000000>       checked;

    unsigned int beg, end, x, y, min_x, min_y, max_x, max_y;

    prime[0]  = 2;
    prime[1]  = 3;
    prime[2]  = 5;
    prime[3]  = 7;
    square[0] = 4;
    square[1] = 9;
    square[2] = 25;
    square[3] = 49;

    for (unsigned int p = 11; p < 46340; p += 2) {
        is_prime = true;
        for (int i = 0; is_prime && i < count && square[i] <= p; ++i) {
            is_prime = p % prime[i] != 0;
        }
        if (is_prime) {
            prime[count]  = p;
            square[count] = p * p;
            ++count;
        }
    }

    while (std::cin >> beg >> end) {
        if (beg < 3) {
            x     = 2;
            y     = 2;
            beg   = 3;
            first = false;
            min_x = 2;
        }
        else {
            beg += beg % 2 ? 0 : 1;
            first = true;
            min_x = beg;
        }
        min_y = end;
        max_x = beg;
        max_y = beg;

        for (unsigned int p = beg; p <= end; p += 2) {
            is_prime = true;
            for (int i = 0; is_prime && i < count && square[i] <= p; ++i) {
                is_prime = (p % prime[i] != 0);
            }
            if (is_prime) {
                if (first) {
                    x     = p;
                    y     = p;
                    first = false;
                }
                else {
                    x = y;
                    y = p;
                    if (x != y) {
                        if (y - x > max_y - max_x) {
                            max_x = x;
                            max_y = y;
                        }
                        if (y - x < min_y - min_x) {
                            min_x = x;
                            min_y = y;
                        }
                    }
                }
            }
        }

        if (max_x != max_y) {
            std::cout << min_x << "," << min_y << " are closest, " << max_x
                      << "," << max_y << " are most distant." << std::endl;
        }
        else {
            std::cout << "There are no adjacent primes." << std::endl;
        }
    }

    return 0;
}
