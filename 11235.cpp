#include <algorithm>
#include <iostream>

struct Number {
    int value, beg, end, size;
};

bool compare_number(const Number &x, const Number &y)
{
    return x.size == y.size ? x.beg < y.beg : x.size > y.size;
}

int main(void)
{
    int    length, num_query, num_value, tmp;
    int    beg, end, idx, freq_size;
    Number numbers[100001], beg_num;

    while (1) {
        std::cin >> length;
        if (!length) break;
        std::cin >> num_query;

        num_value = 0;
        std::cin >> numbers[0].value;
        numbers[0].beg  = 1;
        numbers[0].size = 1;
        for (int i = 1; i < length; ++i) {
            std::cin >> tmp;
            if (tmp == numbers[num_value].value)
                ++numbers[num_value].size;
            else {
                if (numbers[num_value].size > 1) {
                    numbers[num_value].end =
                        numbers[num_value].beg + numbers[num_value].size - 1;
                    numbers[++num_value].value = tmp;
                }
                else {
                    numbers[num_value].value = tmp;
                }
                numbers[num_value].beg  = i + 1;
                numbers[num_value].size = 1;
            }
        }
        numbers[num_value].end =
            numbers[num_value].beg + numbers[num_value].size - 1;
        ++num_value;
        std::sort(numbers, numbers + num_value, compare_number);

        for (int k = 0; k < num_query; ++k) {
            std::cin >> beg >> end;
            freq_size = 1;
            for (int i = 0; i < num_value && numbers[i].size > freq_size; ++i) {
                if (numbers[i].end < beg || end < numbers[i].beg) continue;
                if (numbers[i].beg < beg) {
                    if (numbers[i].end < end) {
                        freq_size =
                            std::max(freq_size, numbers[i].end - beg + 1);
                    }
                    else {
                        freq_size = end - beg + 1;
                        break;
                    }
                }
                else {
                    if (numbers[i].end <= end) {
                        freq_size = numbers[i].size;
                        break;
                    }
                    else {
                        freq_size =
                            std::max(freq_size, end - numbers[i].beg + 1);
                    }
                }
            }
            std::cout << freq_size << std::endl;
        }
    }

    return 0;
}
