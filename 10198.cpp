#include <cstring>
#include <iomanip>
#include <iostream>

#define BASE 1000000000000000000

struct Big {
    int  size;
    long digits[100];
} table[1001];

void show_big(const Big &x)
{
    std::cout << x.digits[x.size - 1];
    for (int i = x.size - 2; i > -1; --i)
        std::cout << std::setfill('0') << std::setw(18) << x.digits[i];
    std::cout << std::endl;
}

void generate_table()
{
    memset(table[0].digits, 0, sizeof(table[0].digits));
    table[0].size      = 1;
    table[0].digits[0] = 1;
    memset(table[1].digits, 0, sizeof(table[1].digits));
    table[1].size      = 1;
    table[1].digits[0] = 2;
    memset(table[2].digits, 0, sizeof(table[2].digits));
    table[2].size      = 1;
    table[2].digits[0] = 5;
    memset(table[3].digits, 0, sizeof(table[3].digits));
    table[3].size      = 1;
    table[3].digits[0] = 13;

    for (int i = 4; i <= 1000; ++i) {
        memset(table[i].digits, 0, sizeof(table[i].digits));
        memcpy(&table[i], &table[i - 1], sizeof(Big));
        table[i].digits[0] *= 2;
        table[i].digits[0] += table[i - 2].digits[0] + table[i - 3].digits[0];
        for (int j = 1; j < table[i].size; ++j) {
            table[i].digits[j] *= 2;
            table[i].digits[j] +=
                table[i - 2].digits[j] + table[i - 3].digits[j];
            table[i].digits[j] += table[i].digits[j - 1] / BASE;
            table[i].digits[j - 1] %= BASE;
        }
        if (table[i].digits[table[i].size - 1] >= BASE) {
            table[i].digits[table[i].size] =
                table[i].digits[table[i].size - 1] / BASE;
            table[i].digits[table[i].size - 1] %= BASE;
            ++table[i].size;
        }
    }
}

int main(void)
{
    generate_table();

    int sum;
    while (std::cin >> sum) {
        show_big(table[sum]);
    }

    return 0;
}
