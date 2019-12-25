#include <iostream>
#include <queue>
#include <string>

int main(void)
{
    int             num_case, len, num_car;
    int             count, size, remain;
    std::string     direction;
    std::queue<int> right, left;

    std::cin >> num_case;
    while (num_case--) {
        std::cin >> len >> num_car;
        len *= 100;
        for (int i = 0; i < num_car; ++i) {
            std::cin >> size >> direction;
            if (direction == "left")
                left.push(size);
            else if (direction == "right")
                right.push(size);
        }

        count = 0;
        while (1) {
            remain = len;
            while (!left.empty() && remain >= left.front()) {
                remain -= left.front();
                left.pop();
            }
            ++count;
            if (left.empty() && right.empty()) break;
            remain = len;
            while (!right.empty() && remain >= right.front()) {
                remain -= right.front();
                right.pop();
            }
            ++count;
            if (left.empty() && right.empty()) break;
        }

        std::cout << count << std::endl;
    }

    return 0;
}
