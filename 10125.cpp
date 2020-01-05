#include <algorithm>
#include <array>
#include <iostream>
#include <map>

int main(void)
{
    bool found;
    int  size, a, b, c, d;

    std::array<int, 1000> num;
    std::map<int, bool>   exist;

    while (1) {
        std::cin >> size;
        if (!size) break;

        exist.clear();
        for (int i = 0; i < size;) {
            std::cin >> num[i];
            if (exist[num[i]])
                --size;
            else
                exist[num[i++]] = true;
        }

        found = false;
        if (size >= 4) {
            std::sort(num.begin(), num.begin() + size);

            for (d = size - 1; !found && d > -1; --d) {
                for (c = size - 1; !found && c > 1; --c) {
                    if (c == d) continue;
                    b = c - 1 == d ? c - 2 : c - 1;
                    a = b - c == d ? b - 2 : b - 1;
                    if (num[c] + num[b] + num[a] < num[d]) break;
                    a = 0 == d ? 1 : 0;
                    b = a + 1 == d ? a + 2 : a + 1;
                    if (num[c] + num[b] + num[a] > num[d]) continue;
                    for (b = c - 1; !found && b > 0; --b) {
                        if (b == d) continue;
                        a = num[d] - num[c] - num[b];
                        if (a >= num[b]) break;
                        if (exist[a] && a != num[d]) {
                            found = true;
                            std::cout << num[d] << std::endl;
                        }
                    }
                }
            }
        }

        if (!found) {
            std::cout << "no solution" << std::endl;
        }
    }

    return 0;
}
