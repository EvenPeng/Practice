#include <cmath>
#include <iostream>

long prime[10000], num_prime;

void generate_prime()
{
    prime[0]  = 2;
    prime[1]  = 3;
    num_prime = 2;

    long root = 2;
    for (long i = 5; i < pow(2, 16); i += 2) {
        if (root * root < i) ++root;
        bool is_prime = true;
        for (long j = 1; is_prime && prime[j] < root; ++j)
            is_prime = (i % prime[j]) > 0;
        if (is_prime) prime[num_prime++] = i;
    }
}

long count_factor(long x, long y)
{
    long sum = 0, base = y;

    while (x / y) {
        sum += x / y;
        y *= base;
    }

    return sum;
}

bool is_dividable(long dividend, long divisor)
{
    long num_factor;

    for (long i = 0; divisor > 1 && i < num_prime && prime[i] <= divisor; ++i)
        if (divisor % prime[i] == 0) {
            num_factor = count_factor(dividend, prime[i]);
            while (num_factor && divisor % prime[i] == 0) {
                --num_factor;
                divisor /= prime[i];
            }
            if (!num_factor && divisor % prime[i] == 0) return false;
        }

    return dividend > divisor || divisor == 1;
}

int main(void)
{
    long dividend, divisor;

    generate_prime();

    while (std::cin >> dividend >> divisor) {
        if (dividend >= divisor || is_dividable(dividend, divisor))
            std::cout << divisor << " divides " << dividend << "!" << std::endl;
        else
            std::cout << divisor << " does not divide " << dividend << "!"
                      << std::endl;
    }

    return 0;
}
