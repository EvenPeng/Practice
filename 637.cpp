#include <array>
#include <iostream>

int main(void)
{
    bool forward;
    int  num_page;

    std::array<int, 100> page;

    while (1) {
        std::cin >> num_page;
        if (!num_page) break;

        std::cout << "Printing order for " << num_page
                  << " pages:" << std::endl;
        if (num_page == 1) {
            std::cout << "Sheet 1, front: Blank, 1" << std::endl;
            continue;
        }

        page.fill(0);
        forward = true;
        for (int idx = 1, i = 1; i <= num_page; ++i) {
            page[idx] = i;
            if (forward) {
                if (idx % 4 == 2 && i * 2 >= num_page) {
                    forward = false;
                    ++idx;
                }
                else {
                    idx += idx % 4 < 2 ? 1 : 3;
                }
            }
            else {
                idx -= idx % 4 ? 3 : 1;
            }
        }

        for (int i = 0; i < num_page; i += 4) {
            std::cout << "Sheet " << (i / 4) + 1 << ", front: ";
            if (!page[i])
                std::cout << "Blank";
            else
                std::cout << page[i];
            std::cout << ", ";
            if (!page[i + 1])
                std::cout << "Blank";
            else
                std::cout << page[i + 1];
            std::cout << std::endl;

            std::cout << "Sheet " << (i / 4) + 1 << ", back : ";
            if (!page[i + 2])
                std::cout << "Blank";
            else
                std::cout << page[i + 2];
            std::cout << ", ";
            if (!page[i + 3])
                std::cout << "Blank";
            else
                std::cout << page[i + 3];
            std::cout << std::endl;
        }
    }

    return 0;
}
