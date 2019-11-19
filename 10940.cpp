#include <iostream>

int main(void)
{
    bool skip_head;
    int  num, head, step;

    while (1) {
        std::cin >> num;
        if (!num) break;

        head      = 1;
        step      = 1;
        skip_head = false;
        while (num > 1) {
            if (!skip_head) {
                head += step;
                skip_head = num % 2;
                num -= (num + 1) / 2;
            }
            else {
                skip_head = (num - 1) % 2;
                num -= num / 2;
            }
            step *= 2;
        }

        std::cout << head << std::endl;
    }

    return 0;
}
