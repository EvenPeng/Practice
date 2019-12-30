#include <array>
#include <iostream>

int main(void)
{
    int num_soldier, num_report;
    int beg, end, hit_beg, hit_end;

    std::array<int, 100002> left, right;

    while (1) {
        std::cin >> num_soldier >> num_report;
        if (!num_soldier && !num_report) break;

        for (int i = 0; i <= num_soldier + 1; ++i) {
            left[i]  = i;
            right[i] = i;
        }

        for (int i = 0; i < num_report; ++i) {
            std::cin >> hit_beg >> hit_end;
            beg = hit_beg - 1;
            while (beg > 0 && left[beg] != beg) {
                beg = left[beg];
            }
            left[hit_end] = beg;

            end = hit_end + 1;
            while (end < num_soldier + 1 && right[end] != end) {
                end = right[end];
            }
            right[hit_beg] = end;

            if (beg == 0)
                std::cout << "* ";
            else
                std::cout << beg << " ";
            if (end == num_soldier + 1)
                std::cout << "*" << std::endl;
            else
                std::cout << end << std::endl;
        }

        std::cout << "-" << std::endl;
    }

    return 0;
}
