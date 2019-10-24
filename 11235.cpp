#include <algorithm>
#include <iostream>

struct Number {
    int value, index;
};

bool compare_number(const Number &x, const Number &y)
{
    return x.index < y.index;
}

int main(void)
{
    int    length, num_query, num_value, tmp;
    int    beg, end, idx, freq_idx, freq_size;
    Number numbers[100001], beg_num;

    while (1) {
        std::cin >> length;
        if (!length) break;
        std::cin >> num_query;

        num_value = 0;
        std::cin >> numbers[0].value;
        numbers[0].index = 1;
        for (int i = 1; i < length; ++i) {
            std::cin >> tmp;
            if (tmp == numbers[num_value].value)
                ++numbers[num_value].index;
            else {
                numbers[++num_value].value = tmp;
                numbers[num_value].index   = i + 1;
            }
        }
        ++num_value;

        for (int i = 0; i < num_query; ++i) {
            std::cin >> beg >> end;
            beg_num.index = beg;
            idx = int(std::lower_bound(numbers, numbers + num_value, beg_num,
                                       compare_number) -
                      numbers);

            if (numbers[idx].index >= end) {
                freq_size = end - beg + 1;
            }
            else {
                freq_idx  = idx;
                freq_size = numbers[idx].index - beg + 1;
                while (++idx < num_value && numbers[idx].index < end) {
                    if (numbers[idx].index - numbers[idx - 1].index >
                        freq_size) {
                        freq_size = numbers[idx].index - numbers[idx - 1].index;
                        freq_idx  = idx;
                    }
                }
                if (end - numbers[idx - 1].index > freq_size) {
                    freq_size = end - numbers[idx - 1].index;
                    freq_idx  = idx;
                }
            }
            std::cout << freq_size << std::endl;
        }
    }

    return 0;
}
